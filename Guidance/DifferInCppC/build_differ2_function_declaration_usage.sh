mkdir -p build
gcc -Wall -std=c11 function_declaration.c -o build/function_declaration_c
g++ -Wall -std=c++11 function_declaration.cpp -o build/function_declaration_cpp
