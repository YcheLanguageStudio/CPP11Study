//
// Created by cheyulin on 8/11/16.
//
#include <boost/core/ignore_unused.hpp>
#include <iostream>

using namespace std;

int func(int x, int y) {
    int i;
    boost::ignore_unused(x, i);

    return y;
}

void func2() {
    typedef int result_type;
    boost::ignore_unused<result_type>();
}

int main() {
    cout << func(1, 2) << endl;
    func2();

    string str1= nullptr;
}