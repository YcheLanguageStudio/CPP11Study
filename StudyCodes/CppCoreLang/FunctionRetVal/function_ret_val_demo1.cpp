//
// Created by cheyulin on 12/20/16.
//
#include <vector>
#include <iostream>
#include "../../Utilities/pretty_print.h"

#include "../big_object.h"

using namespace std;

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
    //normal construction
    auto big_obj1 = BigObject(-1);
    cout << big_obj1.wrapper_vec << '\n' << endl;

    //elide construction
    BigObject big_obj0 = RetBig();
    cout << big_obj0.wrapper_vec << '\n' << endl;

    //elide construction
    vector<BigObject> my_vec = RetVec();
    for (auto &big_obj:my_vec) {
        cout << big_obj0.wrapper_vec << endl;
    }
    cout << endl;


    big_obj0 = BigObject(9);
    cout << "normal assignment, temporary object move syntax, " << big_obj0.wrapper_vec << '\n' << endl;

    big_obj0 = RetBig();
    cout << "return-by-value assignment, return value object is temporary, move syntax, "
         << big_obj0.wrapper_vec << '\n' << endl;

    big_obj0 = big_obj1;
    cout << "copy assign demo:" << big_obj0.wrapper_vec << big_obj1.wrapper_vec << endl;

    big_obj0 = move(big_obj1);
    cout << "move assign demo:" << big_obj0.wrapper_vec << big_obj1.wrapper_vec << endl;

}