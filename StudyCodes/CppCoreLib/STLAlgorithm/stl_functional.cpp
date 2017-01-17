//
// Created by cheyulin on 1/17/17.
//

#include <unordered_map>
#include <algorithm>
#include <iostream>

#include "../../Utilities/pretty_print.h"

using namespace std;

void DemoAccumulate() {
    auto weight_map = unordered_map<int, double>{{1, 1.9},
                                                 {2, 2.0}};
    cout << weight_map << endl;

    cout << "FoldRight:" << accumulate(begin(weight_map), end(weight_map), 0,
                                       [](auto &&left, auto &&right) { return left + right.second; }) << endl;
}


int main() {
    DemoAccumulate();
}