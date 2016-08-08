//
// Created by cheyulin on 8/7/16.
//

#include <boost/ref.hpp>
#include <boost/assert.hpp>
#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;
using namespace boost;

void basic_demo() {
    int x = 10;
    boost::reference_wrapper<int> rw(x);
    assert(x == rw);          //implicit conversion
    (int &) rw = 100;
    assert(x == 100);

    boost::reference_wrapper<int> rw2(rw);   //copy constructor
    assert(rw2.get() == 100);

    string str;
    boost::reference_wrapper<string> rws(str);
    *rws.get_pointer() = "test reference_wrapper";
    cout << rws.get().size() << endl;

}

void factory_demo() {
    double x = 2.7;
    auto rw = boost::cref(x);
    cout << typeid(rw).name() << endl;

    string str;
    auto rws = boost::ref(str);
    cout << typeid(rws).name() << endl;
}

int main() {
    basic_demo();
    factory_demo();
}