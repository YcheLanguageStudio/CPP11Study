//
// Created by cheyulin on 5/7/16.
//

#include <functional>
#include <iostream>

using namespace std;

class TestClass {
public:
    int integer_;
    function<int()> my_function;

    TestClass(int a) : integer_(a) {
        my_function = [this]() -> int {
            cout << this->integer_ << endl;
        };
    }
};

int main() {
    TestClass my_class(1111);
    my_class.my_function();
}