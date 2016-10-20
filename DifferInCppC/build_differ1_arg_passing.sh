mkdir -p build
gcc -Wall -std=c11 only_value_passing.c -o build/only_value_passing_c
g++ -Wall -std=c++11 ref_passing.cpp -o build/ref_passing_cpp
