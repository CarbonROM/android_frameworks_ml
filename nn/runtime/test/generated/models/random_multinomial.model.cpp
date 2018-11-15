// clang-format off
// Generated file (from: random_multinomial.mod.py). Do not edit
void CreateModel(Model *model) {
  OperandType type0(Type::TENSOR_FLOAT32, {1, 1024});
  OperandType type1(Type::INT32, {});
  OperandType type2(Type::TENSOR_FLOAT32, {2});
  OperandType type3(Type::TENSOR_INT32, {1, 128});
  // Phase 1, operands
  auto input0 = model->addOperand(&type0);
  auto sample_count = model->addOperand(&type1);
  auto seeds = model->addOperand(&type2);
  auto output = model->addOperand(&type3);
  // Phase 2, operations
  static int32_t sample_count_init[] = {128};
  model->setOperandValue(sample_count, sample_count_init, sizeof(int32_t) * 1);
  static float seeds_init[] = {37.0f, 42.0f};
  model->setOperandValue(seeds, seeds_init, sizeof(float) * 2);
  model->addOperation(ANEURALNETWORKS_RANDOM_MULTINOMIAL, {input0, sample_count, seeds}, {output});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {input0},
    {output});
  assert(model->isValid());
}

inline bool is_ignored(int i) {
  static std::set<int> ignore = {0};
  return ignore.find(i) != ignore.end();
}
