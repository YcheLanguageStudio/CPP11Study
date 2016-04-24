cmake_minimum_required(VERSION 3.3)
project(CPP11FeaturesStudy)
set(Boost_INCLUDE_DIR /usr/local/include)
set(Boost_LIBRARY_DIR /usr/local/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

#CppPrimer Basic Test
add_executable(CPP11FeaturesStudy PrimerTest/Test.cpp PrimerTest/Test.h)

#LambdaTest
add_executable(LambdaTest LambdaTest/TestLambda.cpp LambdaTest/lambda.h)
add_executable(CpatureTest LambdaTest/TestCapture.cpp)

#BoostTest
add_executable(CPP11FeaturesStudy2 BoostTest/BoostTest.cpp)
add_executable(BGLFindCliques BoostTest/BGLFindCliquesTest.cpp)
target_link_libraries(CPP11FeaturesStudy2 /usr/local/lib/libboost_regex.so)

#TemplateTest
add_executable(TemplateReview TemplateTest/FirstChapter/FirstTemplateReview.cpp TemplateTest/FirstChapter/FirstTemplateReview.h)
add_executable(TemplateSecond TemplateTest/SecondChapter/SecondTemplateSpecialization.cpp TemplateTest/SecondChapter/SecondTemplateSpecialization.h)
add_executable(TemplateThird TemplateTest/ThirdChapter/ThirdTemplateStudy.cpp TemplateTest/ThirdChapter/ThirdTemplateStudy.h)
add_executable(TemplateThirdTrueType TemplateTest/ThirdChapter/ThirdTemplateTrueType.h TemplateTest/ThirdChapter/ThirdTemplateTrueType.cpp)
add_executable(TemplateTest TemplateTest/TestTemplates.cpp)
add_executable(BoostTestBGL BoostTest/BGLTest.cpp)
add_executable(SmartPtrtest BoostTest/SmartPtrtest.cpp)

#JustTest
add_executable(JustTest JustTest/JustTest.cpp)

#RRefTest
add_executable(ReferenceTest ReferenceTest/RReferencetest.cpp)

#FileSystemTest
add_executable(FileTest FileSystemTest/FileSysTest.cpp)


find_package(Threads)
#PthreadTest
add_executable(PthreadTest PthreadTest/PthreadTest.cpp)
target_link_libraries(PthreadTest ${CMAKE_THREAD_LIBS_INIT})
add_executable(VectorMulTest PthreadTest/VectorMultiplicationTest.cpp)
target_link_libraries(VectorMulTest)