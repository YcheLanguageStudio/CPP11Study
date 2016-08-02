#BoostTest
add_executable(RegexTest ./BoostTest.cpp)
target_link_libraries(RegexTest ${Boost_LIBRARIES})
add_executable(BGLFindCliques ./BGLFindCliquesTest.cpp)
add_executable(BoostTestBGL ./BGLTest.cpp)
add_subdirectory(RangeMeta)