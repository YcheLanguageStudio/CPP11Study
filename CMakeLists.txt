cmake_minimum_required(VERSION 3.3)
project(CPP11FeaturesStudy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Test.cpp
    Test.h)

add_executable(CPP11FeaturesStudy ${SOURCE_FILES})