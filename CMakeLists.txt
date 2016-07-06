cmake_minimum_required(VERSION 3.3)
project(CPP11FeaturesStudy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include(FindPackages.cmake)

#BoostTest
add_executable(RegexTest BoostTest/BoostTest.cpp)
target_link_libraries(RegexTest ${Boost_LIBRARIES})
add_executable(BGLFindCliques BoostTest/BGLFindCliquesTest.cpp)
add_executable(BoostTestBGL BoostTest/BGLTest.cpp)
add_executable(SmartPtrtest BoostTest/SmartPtrtest.cpp)

#FileSystemTest
add_executable(FileTest FileSystemTest/FileSysTest.cpp)

#FunctionalTest
add_executable(BindTest FunctionalTest/BindTest.cpp)
add_executable(FunctionalTest FunctionalTest/FunctionTest.cpp)

#JustTest
add_executable(JustTest JustTest/JustTest.cpp)

#LambdaTest
add_executable(LambdaTest LambdaTest/TestLambda.cpp LambdaTest/lambda.h)
add_executable(CpatureTest LambdaTest/TestCapture.cpp)

#CppPrimer Basic Test
add_executable(CPP11FeaturesStudy PrimerTest/Test.cpp PrimerTest/Test.h)

#OpenMp Test
add_executable(ReduceTest OpenMPTest/ReduceTest.cpp)

#TemplateTest
add_subdirectory(TemplateTest)

#RRefTest
add_executable(ReferenceTest ReferenceTest/RReferencetest.cpp)

#PthreadTest
add_subdirectory(PthreadTest)

#ScopeTest
add_subdirectory(ScopeTest)

#STLTest
add_subdirectory(STLTest)

#RandomTest
add_executable(RandomTest RandomTest/RandomTest.cpp)
