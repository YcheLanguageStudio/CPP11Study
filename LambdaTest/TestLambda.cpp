//
// Created by cheyulin on 1/6/16.
//
#include "lambda.h"

using namespace std;
using namespace yche;

void testFunctionalWithLambda() {
    //Reference LambdaTest function through a function wrapper
    //So that Compiler knows it's return and argument type
    function<int(int)> fib;
    fib = [&fib](int i) -> int {
        return i < 2 ? 1 : fib(i - 1) + fib(i - 2);
    };

    cout << "Test recursive functional object:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << fib(i) << ' ';
    }
    cout << endl;
}

void testTemplateWithLambda(){
    auto fib = Y([](function<int(int)> fib, int i) {
        return i < 2 ? fib(i - 1) + fib(i - 2);
    });

    for (int i = 0; i < 10; i++) {
        cout << fib(i) << ' ';
    }
    cout << endl;
}
int main() {
    testFunctionalWithLambda();
    testTemplateWithLambda();
}