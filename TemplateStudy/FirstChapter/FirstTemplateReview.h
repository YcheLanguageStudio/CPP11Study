//
// Created by cheyulin on 1/7/16.
//

#ifndef CPP11FEATURESSTUDY_FIRSTTEMPLATEREVIEW_H
#define CPP11FEATURESSTUDY_FIRSTTEMPLATEREVIEW_H

#endif //CPP11FEATURESSTUDY_FIRSTTEMPLATEREVIEW_H

#include <iostream>

namespace yche {

//First: Template Class
template<typename T>
class ClassA {
 private:
  T member_;
 public:
  //Universal Reference
  ClassA(T &&);

  void PrintMember();
};

//Second: Template Function
template<typename T>
T Add(T, T);

template<typename DstT, typename SrcT>
DstT CppStyleCast(SrcT);

template<typename DstT, typename SrcT>
DstT CStypleCast(SrcT);

//Third: Integer As Template Parameter, Could not Be Float
template<int i>
class A {
 public:
  void Foo();
};

template<uint8_t a, typename b, void *c>
class B {
};

template<bool my_bool, void (*function)()>
class C {
 public:
  void CallFunction();
};

template<void (A<3>::*member_function)()>
class D {
 public:
  void CallMemberFunction();
};

template<int i>
int Add(int a) {
  return a + i;
}

}
