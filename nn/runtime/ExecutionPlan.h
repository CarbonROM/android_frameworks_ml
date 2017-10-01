/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Classes used to plan how to execute a model across multiple devices.

#ifndef ANDROID_ML_NN_RUNTIME_EXECUTION_PLAN_H
#define ANDROID_ML_NN_RUNTIME_EXECUTION_PLAN_H

#include "HalInterfaces.h"
#include "Memory.h"
#include "NeuralNetworks.h"
#include "Utils.h"

#include <set>

namespace android {
namespace nn {

class CompilationBuilder;
class Device;
class ExecutionBuilder;
class ExecutionPlan;
class Memory;
class ModelBuilder;
class StepExecutor;

class ExecutionStep {
private:
    typedef std::vector<std::pair<uint32_t, uint32_t>> RemapVectorType;
    typedef std::set<std::pair<uint32_t, uint32_t>> SubModelOutputSetType;

public:
    enum OperandKind { INPUT, OUTPUT };

    ExecutionStep(ExecutionPlan* plan,
                  uint32_t stepIndex,
                  std::shared_ptr<ModelBuilder> model,
                  std::shared_ptr<Device> device);
    int addOperation(int operationIndex, const ModelBuilder& fromModel);
    int addOperand(uint32_t fromOperandIndex, uint32_t* toOperandIndex,
                   const ModelBuilder& fromModel, OperandKind kind);

    // Each vector entry is of the form (fromModel index, subModel index)
    const RemapVectorType& getSubModelInputs() const {
        return mSubModelInputs;
    }

    size_t countSubModelOutputs() const;

    void recordSubModelOutput(uint32_t fromModelIndex) {
        const auto it = mOperandMap.find(fromModelIndex);
        nnAssert(it != mOperandMap.end());
        mSubModelOutputs.insert(std::make_pair(fromModelIndex, it->second));
    }

    // If this step has a submodel output of unknown size, sets
    // *hasOutputOfUnknownSize to true; otherwise, leaves it
    // unchanged.
    int finishSubModel(bool* hasOutputOfUnknownSize);

    void dump() const;
private:
    // TODO: Some of the data is working state information that
    // shouldn't be needed after we've constructed but not executed
    // the step.

    ExecutionPlan* mPlan;
    uint32_t mIndex;  // index of step within plan
    std::shared_ptr<ModelBuilder> mSubModel;
    std::shared_ptr<Device> mDevice;  // nullptr signifies CPU
    sp<IPreparedModel> mPreparedSubModel;  // not used for CPU

    // Inputs of original model that are also inputs of this submodel:
    //     (fromModel index, subModel index)
    RemapVectorType mModelInputs;
    // Outputs of original model that are also outputs of this submodel:
    //     (fromModel index, subModel index)
    RemapVectorType mModelOutputs;
    // Temporaries of original model that are inputs of this submodel:
    //     (fromModel index, subModel index)
    RemapVectorType mSubModelInputs;
    // Temporaries of original model that are outputs of this submodel:
    //     (fromModel index, subModel index)
    SubModelOutputSetType mSubModelOutputs;
    // Converts operand indexes from the main model to the submodel.
    std::unordered_map<uint32_t, uint32_t> mOperandMap;
};

class ExecutionPlan {
public:
    ExecutionPlan(const ExecutionPlan&) = delete;
    ExecutionPlan& operator=(const ExecutionPlan&) = delete;

    ExecutionPlan() { }
    ~ExecutionPlan() { delete mBody; }

    // Controller is part of the interface to a mechanism for
    // performing an execution in N steps.
    //
    // Usage pattern:
    // - Instantiate Controller with ExecutionPlan::makeController().
    // - Call ExecutionPlan::next() on Controller N+1 times.  The first N times,
    //   *executor is set to point to a new StepExecutor corresponding
    //   to that step.  The N+1st time, *executor is set to nullptr,
    //   signifying there are no more steps.
    // - If ExecutionPlan::next() returns anything other than ANEURALNETWORKS_NO_ERROR,
    //   a problem has occurred.
    class Controller {
        friend class ExecutionPlan;
    private:
        static const size_t kBadStepIndex = ~size_t(0);

        Controller(const ExecutionPlan* plan, const ExecutionBuilder* executionBuilder) :
                mPlan(plan), mExecutionBuilder(executionBuilder), mNextStepIndex(0) {}
        Controller() {}  // used for error state

        const ExecutionPlan* mPlan = nullptr;
        const ExecutionBuilder* mExecutionBuilder = nullptr;
        size_t mNextStepIndex = kBadStepIndex;
    };

    Controller makeController(const ExecutionBuilder* executionBuilder) const;

    int next(Controller* controller, std::shared_ptr<StepExecutor>* executor) const;

    std::shared_ptr<ExecutionStep> createNewStep(const std::shared_ptr<Device> device);

    void becomeSingleStep(const std::shared_ptr<Device> device,
                          const ModelBuilder* model);

    int finish();

    void recordTemporaryDef(uint32_t fromModelIndex, uint32_t stepIndex) {
        auto& temporaryToDefiningStep = compound()->mTemporaryToDefiningStep;
        nnAssert(temporaryToDefiningStep.count(fromModelIndex) == 0);
        temporaryToDefiningStep.insert(std::make_pair(fromModelIndex, stepIndex));
    }

    void dump() const;

    // TODO: This member function is only temporary, until we finish
    // fully integrating ExecutionPlan with the compilation and
    // execution phases of the NN API.
    //
    // Returns true if the plan is "in scope for execution" -- i.e.,
    // the structure of the plan is such that the
    // currently-implemented execution system ought to be able to
    // handle it.  May return true even if something went wrong with
    // the partitioning and compilation process.
    //
    // true - single partition (even if compilation failed)
    // false - multiple partitions
    bool shouldBeExecutable() const;

private:
    void findSubModelOutputs();

    struct Body {
        virtual ~Body() {}
        virtual void dump() const = 0;
        virtual int finish() = 0;
    };

    struct SimpleBody : Body {
        SimpleBody(std::shared_ptr<Device> device, const ModelBuilder* model) :
                mDevice(device), mModel(model) {}

        void dump() const override;
        int finish() override;

        std::shared_ptr<Device> mDevice;  // nullptr signifies CPU
        const ModelBuilder* mModel;
        sp<IPreparedModel> mPreparedModel;  // not used for CPU
        bool mSuccessfulFinish = false;
    };

    struct CompoundBody : Body {
        void dump() const override;
        int finish() override;

        // TODO: Some of the data is working state information that
        // shouldn't be needed after we've constructed but not
        // executed the plan.

        std::vector<std::shared_ptr<ExecutionStep>> mSteps;

        // Map from original operand index to defining step index.
        // Used for all (and only) TEMPORARY_VARIABLEs.
        std::unordered_map<uint32_t, uint32_t> mTemporaryToDefiningStep;

        // Total number of submodel outputs across all steps.
        size_t mSubModelOutputCount = 0;

        bool mHasSubModelOutputOfUnknownSize = true;
    private:
        void findSubModelOutputs();
    };

    enum { EMPTY, SIMPLE, COMPOUND } mState = EMPTY;
    Body* mBody = nullptr;
    CompoundBody* compound() {
        nnAssert(mState == COMPOUND);
        return static_cast<CompoundBody*>(mBody);
    }
};

}  // namespace nn
}  // namespace android

#endif  // ANDROID_ML_NN_RUNTIME_EXECUTION_PLAN_H
