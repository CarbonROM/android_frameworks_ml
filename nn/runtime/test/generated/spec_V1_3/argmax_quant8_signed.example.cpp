// Generated from argmax_quant8_signed.mod.py
// DO NOT EDIT
// clang-format off
#include "TestHarness.h"
using namespace test_helper;

namespace generated_tests::argmax_quant8_signed {

const TestModel& get_test_model_quant8_signed() {
    static TestModel model = {
        .expectFailure = false,
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .minSupportedVersion = TestHalVersion::V1_3,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int8_t>({1, 2, 4, 3}),
                .dimensions = {2, 2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::SUBGRAPH_INPUT,
                .numberOfConsumers = 1,
                .scale = 1.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM_SIGNED,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 0}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::SUBGRAPH_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0, 1},
                .outputs = {2},
                .type = TestOperationType::ARGMAX
            }},
        .outputIndexes = {2}
    };
    return model;
}

const auto dummy_test_model_quant8_signed = TestModelManager::get().add("argmax_quant8_signed_quant8_signed", get_test_model_quant8_signed());

}  // namespace generated_tests::argmax_quant8_signed

namespace generated_tests::argmax_quant8_signed {

const TestModel& get_test_model_quant8_signed_all_inputs_as_internal() {
    static TestModel model = {
        .expectFailure = false,
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {3},
        .isRelaxed = false,
        .minSupportedVersion = TestHalVersion::V1_3,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int8_t>({}),
                .dimensions = {2, 2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 1.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM_SIGNED,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 0}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::SUBGRAPH_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int8_t>({1, 2, 4, 3}),
                .dimensions = {2, 2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::SUBGRAPH_INPUT,
                .numberOfConsumers = 1,
                .scale = 1.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM_SIGNED,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int8_t>({0}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 1.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM_SIGNED,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({0}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {3, 4, 5},
                .outputs = {0},
                .type = TestOperationType::ADD
            }, {
                .inputs = {0, 1},
                .outputs = {2},
                .type = TestOperationType::ARGMAX
            }},
        .outputIndexes = {2}
    };
    return model;
}

const auto dummy_test_model_quant8_signed_all_inputs_as_internal = TestModelManager::get().add("argmax_quant8_signed_quant8_signed_all_inputs_as_internal", get_test_model_quant8_signed_all_inputs_as_internal());

}  // namespace generated_tests::argmax_quant8_signed

namespace generated_tests::argmax_quant8_signed {

const TestModel& get_test_model_quant8_signed_2() {
    static TestModel model = {
        .expectFailure = false,
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .minSupportedVersion = TestHalVersion::V1_3,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int8_t>({1, 2, 4, 3}),
                .dimensions = {2, 2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::SUBGRAPH_INPUT,
                .numberOfConsumers = 1,
                .scale = 1.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM_SIGNED,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({0}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 1}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::SUBGRAPH_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0, 1},
                .outputs = {2},
                .type = TestOperationType::ARGMAX
            }},
        .outputIndexes = {2}
    };
    return model;
}

const auto dummy_test_model_quant8_signed_2 = TestModelManager::get().add("argmax_quant8_signed_quant8_signed_2", get_test_model_quant8_signed_2());

}  // namespace generated_tests::argmax_quant8_signed

namespace generated_tests::argmax_quant8_signed {

const TestModel& get_test_model_quant8_signed_all_inputs_as_internal_2() {
    static TestModel model = {
        .expectFailure = false,
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {3},
        .isRelaxed = false,
        .minSupportedVersion = TestHalVersion::V1_3,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int8_t>({}),
                .dimensions = {2, 2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 1.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM_SIGNED,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({0}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 1}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::SUBGRAPH_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int8_t>({1, 2, 4, 3}),
                .dimensions = {2, 2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::SUBGRAPH_INPUT,
                .numberOfConsumers = 1,
                .scale = 1.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM_SIGNED,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int8_t>({0}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 1.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM_SIGNED,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({0}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {3, 4, 5},
                .outputs = {0},
                .type = TestOperationType::ADD
            }, {
                .inputs = {0, 1},
                .outputs = {2},
                .type = TestOperationType::ARGMAX
            }},
        .outputIndexes = {2}
    };
    return model;
}

const auto dummy_test_model_quant8_signed_all_inputs_as_internal_2 = TestModelManager::get().add("argmax_quant8_signed_quant8_signed_all_inputs_as_internal_2", get_test_model_quant8_signed_all_inputs_as_internal_2());

}  // namespace generated_tests::argmax_quant8_signed

namespace generated_tests::argmax_quant8_signed {

const TestModel& get_test_model_quant8_signed_3() {
    static TestModel model = {
        .expectFailure = false,
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .minSupportedVersion = TestHalVersion::V1_3,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int8_t>({1, 2, 4, 3}),
                .dimensions = {2, 2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::SUBGRAPH_INPUT,
                .numberOfConsumers = 1,
                .scale = 1.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM_SIGNED,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({-1}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 0}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::SUBGRAPH_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {0, 1},
                .outputs = {2},
                .type = TestOperationType::ARGMAX
            }},
        .outputIndexes = {2}
    };
    return model;
}

const auto dummy_test_model_quant8_signed_3 = TestModelManager::get().add("argmax_quant8_signed_quant8_signed_3", get_test_model_quant8_signed_3());

}  // namespace generated_tests::argmax_quant8_signed

namespace generated_tests::argmax_quant8_signed {

const TestModel& get_test_model_quant8_signed_all_inputs_as_internal_3() {
    static TestModel model = {
        .expectFailure = false,
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {3},
        .isRelaxed = false,
        .minSupportedVersion = TestHalVersion::V1_3,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int8_t>({}),
                .dimensions = {2, 2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 1.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM_SIGNED,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({-1}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1, 0}),
                .dimensions = {2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::SUBGRAPH_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 0.0f,
                .type = TestOperandType::TENSOR_INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int8_t>({1, 2, 4, 3}),
                .dimensions = {2, 2},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::SUBGRAPH_INPUT,
                .numberOfConsumers = 1,
                .scale = 1.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM_SIGNED,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int8_t>({0}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 1.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM_SIGNED,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({0}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {3, 4, 5},
                .outputs = {0},
                .type = TestOperationType::ADD
            }, {
                .inputs = {0, 1},
                .outputs = {2},
                .type = TestOperationType::ARGMAX
            }},
        .outputIndexes = {2}
    };
    return model;
}

const auto dummy_test_model_quant8_signed_all_inputs_as_internal_3 = TestModelManager::get().add("argmax_quant8_signed_quant8_signed_all_inputs_as_internal_3", get_test_model_quant8_signed_all_inputs_as_internal_3());

}  // namespace generated_tests::argmax_quant8_signed

