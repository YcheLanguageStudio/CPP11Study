cmake_minimum_required(VERSION 3.3)
project(CPP11FeaturesStudy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O0")

include(FindPackages.cmake)

add_subdirectory(StudyCodes/BoostStudy)
add_subdirectory(StudyCodes/FunctionalStudy)
add_subdirectory(StudyCodes/TemplateStudy)
add_subdirectory(StudyCodes/ParallelStudy/PthreadStudy)
add_subdirectory(StudyCodes/ParallelStudy/OpenMpStudy)
add_subdirectory(StudyCodes/STLStudy)
add_subdirectory(StudyCodes/OtherStudy)



