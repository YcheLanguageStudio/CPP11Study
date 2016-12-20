//
// Created by cheyulin on 1/8/16.
//

#ifndef CPP11FEATURESSTUDY_THIRDTEMPLATESTUDY_H
#define CPP11FEATURESSTUDY_THIRDTEMPLATESTUDY_H

#endif //CPP11FEATURESSTUDY_THIRDTEMPLATESTUDY_H

#include <complex>
#include <type_traits>
#include <iostream>

namespace yche {
//Template Proto
template<typename... Ts>
class Y { };

//Template Specialization
//So Varadic Do not Need to Be Put Last
template<typename... Ts, typename U>
class Y<U, Ts...> { };

//Template Default Parameter
template<typename T0, typename T1=void, typename T2=void>
class Tuple {
};

template<typename T>
T CustomDiv(T lhs, T rhs) {
  T v;
  std::cout << "Proto Impl lhs: " << lhs << " ,rhs" << rhs << std::endl;
  return v;
}

//Template Default Parameter Coule be Type Expression
template<typename T, bool IsFloat = std::is_floating_point<T>::value, bool IsIntegral = std::is_integral<T>::value>
struct SafeDivide {
  static T Do(T lhs, T rhs) {
    std::cout << "Template Proto, Not int and float" << std::endl;
    return CustomDiv(lhs, rhs);
  }
};

//Partial Specialization For Float
template<typename T>
struct SafeDivide<T, true, false> {
  static T Do(T lhs, T rhs) {
    std::cout << "Float Partial Specialization " << std::endl;
    return lhs / rhs;
  }
};

//Partial Specialization For Integer
template<typename T>
struct SafeDivide<T, false, true> {
  static T Do(T lhs, T rhs) {
    std::cout << "Integer Partial Specialization" << std::endl;
    return rhs == 0 ? 0 : lhs / rhs;
  }
};

}