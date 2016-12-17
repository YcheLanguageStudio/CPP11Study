//
// Created by cheyulin on 1/8/16.
//

#include <stdint.h>
#include <iostream>
#ifndef CPP11FEATURESSTUDY_SECONDTEMPLATESPECIALIZATION_H
#define CPP11FEATURESSTUDY_SECONDTEMPLATESPECIALIZATION_H

#endif //CPP11FEATURESSTUDY_SECONDTEMPLATESPECIALIZATION_H

namespace yche {
template<typename T>
class TypeToID {
 public:
  static int const ID = -1;
};

//Specialization Examples:
template<>
class TypeToID<uint8_t> {
 public:
  static int const ID = 1;
};

template<typename T>
class TypeToID<T *> {
 public:
  typedef T RemovePtrType;
  static int const ID = 2;
};

template<>
class TypeToID<int *> {
 public:
  static int const ID = 3;
};

template<typename T>
class RemovePointer {
 public:
  typedef T Result;
};

template<typename T>
class RemovePointer<T *> {
 public:
  typedef T Result;
};
}
