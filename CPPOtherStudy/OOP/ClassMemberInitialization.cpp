//
// Created by cheyulin on 8/9/16.
//


#include <iostream>

using namespace std;

struct ClassMine {
    int x_{222};

    ClassMine(int x) : x_(x) {}

    ClassMine() = default;
};

int main() {
    ClassMine class1(333);
    cout << class1.x_ << endl;

    //Copy Constructor
    ClassMine class2 = class1;
    cout << class2.x_ << endl;

    class2.x_ = 444;
    cout << class1.x_ << endl;
    cout << class2.x_ << endl;

    //Default Member Initialization
    ClassMine class3;
    cout << class3.x_ << endl;

}