//
// Created by cheyulin on 9/16/16.
//
#include <iostream>

using namespace std;

struct function_object {
    int operator()(int a, int b) {
        return a + b;
    }
};

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    //Declare
    int (*function_ptr)(int, int);

    //You can get the address of a function simply by naming it:
    //Or by prefixing the name of the function with an ampersand:
    function_ptr = add;
    cout << "function pointer demo, add 2 and 3, result:" << function_ptr(2, 3) << endl;

    function_ptr = multiply;
    cout << "function pointer demo, multiply 2 and 3, result:" << function_ptr(2, 3) << endl;

    function_object func_obj;
    cout << "function object demo, add 2 and 3, result:" << func_obj(2, 3) << endl;
}