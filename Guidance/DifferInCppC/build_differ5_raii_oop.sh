mkdir -p build
g++ -Wall -std=c++11 raii_demo.cpp -o build/raii_demo_cpp
gcc -Wall -std=c11 polymorphism_demo.c -o build/polymorphism_demo_c
g++ -Wall -std=c++11 polymorphism_demo.cpp -o build/polymorphism_demo_cpp
