cmake_minimum_required(VERSION 3.3)
project(CPP11FeaturesStudy)
#set(Boost_INCLUDE_DIR /usr/local/include)
#set(Boost_LIBRARY_DIR /usr/local/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

#BoostTest
find_package(Boost 1.58.0 COMPONENTS system filesystem regex REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
add_executable(CPP11FeaturesStudy2 BoostTest/BoostTest.cpp)
target_link_libraries(CPP11FeaturesStudy2 ${Boost_LIBRARIES})
add_executable(BGLFindCliques BoostTest/BGLFindCliquesTest.cpp)
add_executable(BoostTestBGL BoostTest/BGLTest.cpp)
add_executable(SmartPtrtest BoostTest/SmartPtrtest.cpp)
#target_link_libraries(CPP11FeaturesStudy2 /usr/local/lib/libboost_regex.so)

#FileSystemTest
add_executable(FileTest FileSystemTest/FileSysTest.cpp)

#JustTest
add_executable(JustTest JustTest/JustTest.cpp)

#LambdaTest
add_executable(LambdaTest LambdaTest/TestLambda.cpp LambdaTest/lambda.h)
add_executable(CpatureTest LambdaTest/TestCapture.cpp)

#CppPrimer Basic Test
add_executable(CPP11FeaturesStudy PrimerTest/Test.cpp PrimerTest/Test.h)

#TemplateTest
add_executable(TemplateReview TemplateTest/FirstChapter/FirstTemplateReview.cpp TemplateTest/FirstChapter/FirstTemplateReview.h)
add_executable(TemplateSecond TemplateTest/SecondChapter/SecondTemplateSpecialization.cpp TemplateTest/SecondChapter/SecondTemplateSpecialization.h)
add_executable(TemplateThird TemplateTest/ThirdChapter/ThirdTemplateStudy.cpp TemplateTest/ThirdChapter/ThirdTemplateStudy.h)
add_executable(TemplateThirdTrueType TemplateTest/ThirdChapter/ThirdTemplateTrueType.h TemplateTest/ThirdChapter/ThirdTemplateTrueType.cpp)
add_executable(TemplateTest TemplateTest/TestTemplates.cpp)
add_executable(TemplateMine TemplateTest/CrazyTemplate.cpp TemplateTest/CrazyTemplate.h TemplateTest/TestTemplates.cpp)

#RRefTest
add_executable(ReferenceTest ReferenceTest/RReferencetest.cpp)

#PthreadTest
find_package(Threads)
add_executable(PthreadTest PthreadTest/PthreadTest.cpp)
target_link_libraries(PthreadTest ${CMAKE_THREAD_LIBS_INIT})
add_executable(VectorMulTest PthreadTest/VectorMultiplicationTest.cpp)
target_link_libraries(VectorMulTest ${CMAKE_THREAD_LIBS_INIT})
add_executable(RaceConditionTest PthreadTest/RaceConditionTest.cpp)
target_link_libraries(RaceConditionTest ${CMAKE_THREAD_LIBS_INIT})
add_executable(SemaPhoreTest PthreadTest/SemephoreTest.cpp)
target_link_libraries(SemaPhoreTest ${CMAKE_THREAD_LIBS_INIT})
add_executable(BarrierTest PthreadTest/BarrierTest.cpp)
target_link_libraries(BarrierTest ${CMAKE_THREAD_LIBS_INIT})
