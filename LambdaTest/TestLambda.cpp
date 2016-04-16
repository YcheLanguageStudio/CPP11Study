//
// Created by cheyulin on 1/6/16.
//
#include "lambda.h"
#include <algorithm>

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

//void testTemplateWithLambda(){
//    auto fib = Y([](function<int(int)> fib, int i) {
//        return i < 2 ? fib(i - 1) + fib(i - 2);
//    });
//
//    for (int i = 0; i < 10; i++) {
//        cout << fib(i) << ' ';
//    }
//    cout << endl;
//}

int main() {
    testFunctionalWithLambda();
    vector<pair<int, int>> my_vec;
    my_vec.push_back(make_pair(1, 4));
    my_vec.push_back(make_pair(2, 3));
    my_vec.push_back(make_pair(5, 2));
    sort(my_vec.begin(), my_vec.end(), [](auto &a, auto &b) -> bool {
        return a.first + 2 * a.second < b.first + 2 * b.second;
    });

    for (auto &my_pair:my_vec) {
        cout << my_pair.first << "," << my_pair.second << "\t" << (my_pair.first + my_pair.second * 2) << endl;
    }
//    testTemplateWithLambda();
    getchar();
}