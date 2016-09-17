g++ -c cpp_invoke_c_funcs.cpp -o cpp_invoke_c_funcs.o
gcc -c c_functions.c -o c_functions.o
gcc cpp_invoke_c_funcs.o c_functions.o -lstdc++ -o test_cpp_invoke_c