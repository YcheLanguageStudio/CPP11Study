mkdir -p build
gcc -Wall -std=c11 pre_processing.c -o build/pre_processing_c
g++ -Wall -std=c++11 function_template.cpp -o build/function_template_cpp
