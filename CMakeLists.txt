cmake_minimum_required(VERSION 3.3)
project(CPP11FeaturesStudy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include(FindPackages.cmake)

add_subdirectory(BoostStudy)
add_subdirectory(FunctionalStudy)
add_subdirectory(TemplateStudy)
add_subdirectory(ParallelStudy/PthreadStudy)
add_subdirectory(ParallelStudy/OpenMpStudy)
add_subdirectory(STLStudy)
add_subdirectory(CPPOtherStudy)



