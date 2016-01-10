//
// Created by cheyulin on 1/8/16.
//

#include "ThirdTemplateStudy.h"

void foo() {
  std::cout << "Float Divide Result:" << yche::SafeDivide<float>::Do(1.0f, 2.0f) << std::endl;
  std::cout << "Integer Divide Result:" << yche::SafeDivide<int>::Do(3, 2) << std::endl;
  std::cout << "Integer Divide Result:" << yche::SafeDivide<int>::Do(2, 0) << std::endl;
  std::cout << "Complex Divide Result:" << yche::SafeDivide<std::complex<float>>::Do({1.f, 2.f}, {1.f, -2.f});
}

int main() {
  foo();
}