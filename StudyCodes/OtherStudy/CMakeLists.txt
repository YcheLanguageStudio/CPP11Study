#ScopeTest
add_executable(StaticTest ScopeTest/StaticTest.cpp)
add_executable(ScopeTest ScopeTest/ScopeTest.cpp)
add_executable(BreakTest ScopeTest/BreakTest.cpp)

#Random Generation Test
add_executable(RandomTest RandomTest/RandomTest.cpp)

#File System Study
add_executable(FileTest FileSystemTest/FileSysTest.cpp)

add_subdirectory(OOP)

add_subdirectory(EnumClassStudy)