//
// Created by cheyulin on 7/22/16.
//
#include <iostream>

using namespace std;
auto lambda = [](int i) { cout << i << endl; };

struct MyClass {
    static decltype(lambda) print;
    void print_me();
    void print_hi();
};
decltype(lambda) MyClass::print = lambda;

void MyClass::print_me() {
    print(1);
    print(2);
}

void MyClass::print_hi() {
    lambda(3);
    lambda(4);

}

int main() {
    MyClass myClass;
    myClass.print_me();
    myClass.print_hi();
}