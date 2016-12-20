//
// Created by cheyulin on 8/8/16.
//
#include <vector>
#include <string>
#include <typeinfo>
#include <boost/ref.hpp>
#include <boost/assert.hpp>
#include <iostream>

using namespace std;
using namespace boost;

int main() {
    vector<int> v(10, 2);
    auto rw = boost::cref(v);

    assert(is_reference_wrapper<decltype(rw)>::value);
    assert(!is_reference_wrapper<decltype(v)>::value);


    string str;
    auto rws = boost::ref(str);
    cout << typeid(unwrap_reference<decltype(rws)>::type).name() << endl;
    cout << typeid(unwrap_reference<decltype(str)>::type).name() << endl;
}