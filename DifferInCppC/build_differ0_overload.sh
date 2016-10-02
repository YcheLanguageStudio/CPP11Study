mkdir -p build
gcc -Wall -std=c11 non_overload.c -o build/non_overload_c
g++ -Wall -std=c++11 with_overload.cpp -o build/overload_cpp
