//
// Created by cheyulin on 8/8/16.
//
#include <iostream>

using namespace std;

struct Class1 {
    int i;

    Class1(int i) : i(i) {
        cout << "constructor class 1" << endl;
        cout << i << endl;
    }
};

struct Class2 {
    Class1 class1;

    Class2(int integer) : class1(integer) {
        cout << "constructor class 2" << endl;
    }
};

int main() {
    Class2 my_class(20);
}


