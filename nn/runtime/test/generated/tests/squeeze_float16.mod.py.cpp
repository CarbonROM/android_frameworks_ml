// clang-format off
// Generated file (from: squeeze_float16.mod.py). Do not edit
#include "../../TestGenerated.h"

namespace squeeze_float16 {
// Generated squeeze_float16 test
#include "generated/examples/squeeze_float16.example.cpp"
// Generated model constructor
#include "generated/models/squeeze_float16.model.cpp"
} // namespace squeeze_float16

TEST_F(GeneratedTests, squeeze_float16) {
    execute(squeeze_float16::CreateModel,
            squeeze_float16::is_ignored,
            squeeze_float16::get_examples());
}
