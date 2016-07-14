//
// Created by cheyulin on 5/7/16.
//

#include <boost/bind.hpp>
#include <iostream>
#include <assert.h>

using namespace boost;
using namespace std;

int Add(int a, int b) {
    return a + b;
}

void TestBasicFunction() {
    auto x = 1;
    auto y = 3;
    cout << bind(Add, 1, 2)() << endl;
    //Use Placeholder
    cout << bind(Add, _1, _1)(x, y, y) << endl;
    cout << bind(Add, _1, _2)(x, y) << endl;
    //Bind Function Ptr (LValue)
    typedef decltype(&Add) add_t;
    add_t function_ptr = Add;

    cout << bind(function_ptr, _2, _2)(x, y) << endl;
}


struct Demo {
    int Multiplication(int a, int b) {
        return a * b;
    }
};

void TestClassMemberFunction() {
    Demo demo;
    Demo &ref_demo = demo;
    Demo *ptr_demo = &demo;
    auto x = 2;
    auto y = 3;
    cout << boost::bind(&Demo::Multiplication, demo, _1, _2)(x, x) << endl;
    cout << boost::bind(&Demo::Multiplication, ref_demo, _1, _2)(x, y) << endl;
    cout << boost::bind(&Demo::Multiplication, ptr_demo, _1, _2)(y, y) << endl;
}

//C++11 Lambda Expression
auto AddTwo = [](int x) {
    return Add(x, 2);
};

void TestLambdaComparedWithBind() {
    assert(AddTwo(4) == boost::bind(Add, _1, 2)(4));
    cout << "HI" << endl;
}

//With varadic templates

int main() {
    TestBasicFunction();
    cout << endl << endl;
    TestClassMemberFunction();
    cout << endl << endl;
    TestLambdaComparedWithBind();
    getchar();
}
