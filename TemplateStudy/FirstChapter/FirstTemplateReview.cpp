//
// Created by cheyulin on 1/7/16.
//

#include "FirstTemplateReview.h"

//First: Template Class
template<typename T>
void yche::ClassA<T>::PrintMember() {
  std::cout << "Member:" << member_ << std::endl;
}

template<typename T>
yche::ClassA<T>::ClassA(T &&member) {
  member_ = member;
}

void TestTemplateClass() {
  yche::ClassA<int> class_int(123);
  yche::ClassA<std::string> class_string(std::string("123"));
  class_int.PrintMember();
  class_string.PrintMember();
}

//Second: Template Function
template<typename T>
T yche::Add(T a, T b) {
  return a + b;
}

void TestTemplateFunctionAdd() {
  //Normal
  std::cout << yche::Add<int>(1, 2) << std::endl;
  //Type Deduction
  int left_int = 1;
  int right_int = 2;
  std::cout << yche::Add(left_int, right_int) << std::endl;
  /* Type Deduction Failure
      char left = 1;
      int right = 2;
      yche::Add(left,right);
  */
}

template<typename T, typename R>
T yche::CppStyleCast(R param) {
  return static_cast<T>(param);
}

template<typename DstT, typename SrcT>
DstT yche::CStypleCast(SrcT src_param) {
  return (DstT) (src_param);
}

void TestTemplateFunctionCastValue() {
  int i = 1;
  //Must specify float
  //Since compiler could not deduce from the return type

  float a = yche::CppStyleCast<float>(i);
  std::cout << "Cpp Style After cast:" << a << " ,Before:" << i << std::endl;

  a = yche::CStypleCast<float>(i);
  std::cout << "C Styple After cast:" << a << " ,Before:" << i << std::endl;
}

//Third: Integer As Template Parameter
template<int i>
void yche::A<i>::Foo() {
  std::cout << "Called From A, Hello,Fooer " << i << std::endl;
}

template<bool my_bool, void (*function)()>
void yche::C<my_bool, function>::CallFunction() {
  if (my_bool == false)
    function();
}

void SayHello() {
  std::cout << "Called From C,Hello" << std::endl;
  return;
}

//Member Function As Parameter
template<void (yche::A<3>::*member_function)()>
void yche::D<member_function>::CallMemberFunction() {
  A<3> a;
  std::cout << "Called From D,Hi ;";
  (a.*member_function)();

}

void TestPrimitiveTypeAsParam() {
  yche::A<5> fooer;
  fooer.Foo();

  yche::B<7, yche::A<5>, nullptr> b;

  yche::C<false, SayHello> c;
  c.CallFunction();

  yche::D<&yche::A<3>::Foo> d;
  d.CallMemberFunction();

  std::cout << "From Add,2+3:" << yche::Add<2>(3) << std::endl;
}

int main() {
  TestTemplateClass();
  TestTemplateFunctionAdd();
  TestTemplateFunctionCastValue();
  TestPrimitiveTypeAsParam();
}



