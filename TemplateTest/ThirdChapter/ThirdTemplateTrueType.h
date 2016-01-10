//
// Created by cheyulin on 1/10/16.
//

#ifndef CPP11FEATURESSTUDY_THIRDTEMPLATETRUETYPE_H
#define CPP11FEATURESSTUDY_THIRDTEMPLATETRUETYPE_H

#endif //CPP11FEATURESSTUDY_THIRDTEMPLATETRUETYPE_H

#include <iostream>
#include <complex>
#include <type_traits>

namespace yche {

template<typename T>
T CustomDiv(T lhs, T rhs) {
  T v;
  std::cout << "Proto Impl lhs: " << lhs << " ,rhs" << rhs << std::endl;
  return v;
}

//Template Default Parameter Coule be Type Expression
template<typename T, typename Enabled=std::true_type>
struct SafeDivide {
  static T Do(T lhs, T rhs) {
    std::cout << "Template Proto, Not int and float" << std::endl;
    return CustomDiv(lhs, rhs);
  }
};

//Partial Specialization For Float
template<typename T>
struct SafeDivide<T,typename std::is_floating_point<T>::type> {
  static T Do(T lhs, T rhs) {
    std::cout << "Float Partial Specialization " << std::endl;
    return lhs / rhs;
  }
};

//Partial Specialization For Integer
template<typename T>
struct SafeDivide<T,typename  std::is_integral<T>::type> {
  static T Do(T lhs, T rhs) {
    std::cout << "Integer Partial Specialization" << std::endl;
    return rhs == 0 ? 0 : lhs / rhs;
  }
};

}