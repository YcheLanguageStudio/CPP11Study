//
// Created by cheyulin on 4/14/16.
//
#include <iostream>
#include <algorithm>

#include "../../Utilities/pretty_print.h"

using namespace std;

void DemoForwardRef(auto &&input) {
    cout << input << endl;
}

int main() {
    auto integer_ptr = make_unique<int>(1);
    auto integer = 2;
    auto my_str = string("haha");

    DemoForwardRef(integer);
    DemoForwardRef(my_str);
    DemoForwardRef(move(my_str));
    DemoForwardRef(*integer_ptr);
}