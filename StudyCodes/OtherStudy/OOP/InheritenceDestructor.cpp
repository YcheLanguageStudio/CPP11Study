//
// Created by cheyulin on 8/9/16.
//
#include <iostream>

using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base Destructor" << endl;
    }
};

class Derived : public Base {
public:
    virtual ~Derived() {
        cout << "Derived Destructor" << endl;
    }
};

class BaseWithoutVirtual {
public:
    ~BaseWithoutVirtual() {
        cout << "Base W/O Virtual" << endl;
    }
};

class DerivedWithoutVirtual : public BaseWithoutVirtual {
public:
    ~DerivedWithoutVirtual() {
        cout << "Derived W/O Virtual" << endl;

    }
};

int main() {
    Derived();
    DerivedWithoutVirtual();
}