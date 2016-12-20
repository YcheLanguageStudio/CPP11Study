//
// Created by cheyulin on 12/20/16.
//
#include <vector>
#include <iostream>
#include "../../Utilities/pretty_print.h"

using namespace std;

struct BigObject {
    vector<int> integer;

    BigObject(int i) : integer(10, i) { cout << "Construct with " << i << endl; }

    BigObject(const BigObject &other) { cout << "Copy Construct" << endl; };

    BigObject(BigObject &&other) { cout << "Move Construct" << endl; }

    BigObject &operator=(const BigObject &other) {
        cout << "Copy Assign" << endl;
        this->integer = other.integer;
        return *this;
    }

    BigObject &operator=(BigObject &&other) {
        cout << "Move Assign" << endl;
        this->integer = move(other.integer);
        return *this;
    }
};

BigObject RetBig() {
    static int num = 5;
    BigObject big_obj(num);
    num++;
    return big_obj;
}

vector<BigObject> RetVec() {
    vector<BigObject> my_vec;
    my_vec.reserve(20);
    for (auto i = 0; i < 5; i++) { my_vec.emplace_back(i); }
    //try move first, then copy, and both move and copy is possibly elided.
    return my_vec;
}


int main() {
    vector<BigObject> my_vec = RetVec();
    for (auto &big_obj:my_vec) {
        cout << big_obj.integer << endl;
    }
    cout << endl;

    //elide construction
    BigObject big_obj = RetBig();
    cout << big_obj.integer << '\n' << endl;

    //move assignment
    big_obj = RetBig();
    cout << big_obj.integer << '\n' << endl;

    //move assignment
    big_obj = BigObject(9);
    cout << big_obj.integer << '\n' << endl;
}