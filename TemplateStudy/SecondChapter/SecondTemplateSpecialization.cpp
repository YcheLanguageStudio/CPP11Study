//
// Created by cheyulin on 1/8/16.
//

#include "SecondTemplateSpecialization.h"

//Partial Specialization or Specialization Has the Meaning of         if-then-else
//Via Type Deduction of Compiler to Help us Choose Different Needs
void TestTypeInfoID() {
  std::cout << "uint8_t type: " << yche::TypeToID<uint8_t>::ID << std::endl;
  std::cout << "int type: " << yche::TypeToID<int>::ID << std::endl;
  std::cout << "ptr type: " << yche::TypeToID<float *>::ID << std::endl;
  std::cout << "int prt type: " << yche::TypeToID<int *>::ID << std::endl;
  std::cout << std::endl;
};

void TestRemovePointer() {
  yche::RemovePointer<float *>::Result x = 5.0f;
  yche::RemovePointer<double>::Result y =6.0;
  std::cout << "x val:" << x << std::endl;
  std::cout << "y val:" << y << std::endl;
}

int main() {
  TestTypeInfoID();
  TestRemovePointer();
}