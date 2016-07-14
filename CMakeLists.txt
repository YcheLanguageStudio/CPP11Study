cmake_minimum_required(VERSION 3.3)
project(CPP11FeaturesStudy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include(FindPackages.cmake)

add_subdirectory(BoostTest)



add_subdirectory(FunctionalStudy/FunctionalTest)

add_subdirectory(FunctionalStudy/LambdaStudy)

add_executable(ReduceTest ParallelStudy/OpenMpStudy/ReduceTest.cpp)

add_subdirectory(TemplateStudy)


add_subdirectory(ParallelStudy/PthreadStudy)

add_subdirectory(CPPOtherStudy)

add_subdirectory(STLStudy)

