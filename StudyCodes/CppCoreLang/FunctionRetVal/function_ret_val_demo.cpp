//
// Created by cheyulin on 12/22/16.
//
#include <memory>
#include <iostream>

using namespace std;

unique_ptr<int> get_unique() {
    auto ptr = make_unique<int>(2);
    return ptr;
}

int main() {
    auto int_ptr = get_unique();
    cout << *int_ptr << endl;
}