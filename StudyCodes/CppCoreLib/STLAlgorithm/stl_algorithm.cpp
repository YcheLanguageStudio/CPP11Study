//
// Created by cheyulin on 12/22/16.
//

#include <iostream>
#include <vector>
#include "../../Utilities/pretty_print.h"

using namespace std;

void DemoSTLAssignErase() {
    cout << "hello" << endl;

    vector<double> vec0;
    vector<double> vec1;
    for (auto i = 0; i < 10; ++i) { vec0.emplace_back(i); }

    vec1.assign(vec0.begin() + 1, vec0.end());
    vec1.erase(vec1.begin() + 1);
    cout << vec1 << endl;
}


int main() {
    DemoSTLAssignErase();
}
