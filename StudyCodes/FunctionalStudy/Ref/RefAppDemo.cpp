//
// Created by cheyulin on 8/8/16.
//
#include <iostream>
#include <boost/ref.hpp>

using namespace std;
using namespace boost;

class big_class {
private:
    int x;
public:
    big_class() : x(0) {}

    void print() {
        cout << "big_class " << ++x << endl;
    }
};

template<typename T>
void print(T a) {
    for (auto i = 0; i < 2; ++i) {
        unwrap_ref(a).print();
    }
}

int main() {
    big_class c;
    auto rw = ref(c);

    c.print();          // print 1

    print(c);           //copy passing param , not change c state
    print(rw);          //ref passing param, change c state
    print(c);
    c.print();
}