//
// Created by cheyulin on 1/6/16.
//
#include "lambda.h"
#include <algorithm>
#include  <memory>
#include <set>

using namespace std;
using namespace yche;

void testFunctionalWithLambda() {
    //Reference LambdaStudy function through a function wrapper
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

struct complex_struct {
    complex_struct(int integer) : integer(integer) { }

    int integer;
    double w1;
    double w2;

//    bool operator==(const complex_struct &right_struct) {
//        return this->integer == right_struct.integer;
//    }
};

struct test {
    test(int shit) : shit(shit) { }

    int shit;
};

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

    vector<unique_ptr<test>> ptr_vec;
    ptr_vec.push_back(std::move(make_unique<test>(1)));
    ptr_vec.push_back(std::move(make_unique<test>(2)));
    ptr_vec.push_back(std::move(make_unique<test>(4)));
    sort(ptr_vec.begin(), ptr_vec.end(), [](auto &&a, auto &&b) -> bool {
        return a->shit > b->shit;
    });
    for (auto &&my_ptr:ptr_vec) {
        cout << my_ptr->shit << endl;
    }
//    testTemplateWithLambda();
    cout << endl << endl;
    auto comp = [](auto &&a, auto &&b) -> bool { return a->integer < b->integer; };
    set<unique_ptr<complex_struct>, decltype(comp)> complex_set(comp);
    auto complex1 = make_unique<complex_struct>(1);
    auto complex2 = make_unique<complex_struct>(3);
    auto complex3 = make_unique<complex_struct>(2);
    complex3->w1 = 1;
    complex3->w2 = 2;
    complex_set.insert(std::move(complex1));
    complex_set.insert(std::move(complex2));
    complex_set.insert(std::move(complex3));

    auto complex = make_unique<complex_struct>(2);
//    auto && r_ref_complex = move(complex);
    auto iter_one = complex_set.find(complex);
    if (iter_one != complex_set.end()) {
        cout << "!!!" << (*iter_one)->w1 << "," << (*iter_one)->w2 << endl;
    }

    for (auto iter = complex_set.begin(); iter_one != complex_set.end(); ++iter_one) {
        cout << (*iter_one)->integer;
    }

    getchar();
}