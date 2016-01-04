cmake_minimum_required(VERSION 3.3)
project(CPP11FeaturesStudy)
set(Boost_INCLUDE_DIR /usr/local/include)
set(Boost_LIBRARY_DIR /usr/local/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Test.cpp Test.h)

add_executable(CPP11FeaturesStudy ${SOURCE_FILES})

add_executable(CPP11FeaturesStudy2 BoostTest/BoostTest.cpp)
target_link_libraries(CPP11FeaturesStudy2 /usr/local/lib/libboost_regex.so)