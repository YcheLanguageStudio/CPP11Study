cmake_minimum_required(VERSION 3.3)
project(CPP11FeaturesStudy)
set(Boost_INCLUDE_DIR /usr/local/include)
set(Boost_LIBRARY_DIR /usr/local/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#CppPrimer Basic Test
add_executable(CPP11FeaturesStudy PrimerTest/Test.cpp PrimerTest/Test.h )

#LambdaTest
add_executable(LambdaTest LambdaTest/TestLambda.cpp LambdaTest/lambda.h)

#BoostTest
add_executable(CPP11FeaturesStudy2 BoostTest/BoostTest.cpp)
target_link_libraries(CPP11FeaturesStudy2 /usr/local/lib/libboost_regex.so)

#TemplateTest
add_executable(TemplateReview TemplateTest/FirstChapter/FirstTemplateReview.cpp TemplateTest/FirstChapter/FirstTemplateReview.h)
add_executable(TemplateSecond TemplateTest/SecondChapter/SecondTemplateSpecialization.cpp TemplateTest/SecondChapter/SecondTemplateSpecialization.h)
add_executable(TemplateThird TemplateTest/ThirdChapter/ThirdTemplateStudy.cpp TemplateTest/ThirdChapter/ThirdTemplateStudy.h)
add_executable(TemplateThirdTrueType TemplateTest/ThirdChapter/ThirdTemplateTrueType.h TemplateTest/ThirdChapter/ThirdTemplateTrueType.cpp)
add_executable(TemplateTest TemplateTest/TestTemplates.cpp)