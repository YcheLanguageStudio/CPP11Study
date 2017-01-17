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

void DemoSortSetUnion() {
    auto v1 = vector<int>{1, 4, 2, 6};
    auto v2 = vector<int>{8, 1, 2, 7, 3};
    vector<int> v3;
    vector<int> v4;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    cout << v1 << v2 << endl;

    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    cout << v3 << endl;

    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v4));
    cout << v4 << endl;
}

void DemoMinElement() {
    auto v = vector<int>();
    auto iter = min_element(begin(v), end(v));
    cout << iter - begin(v) << endl;
    if (iter == v.end()) {
        cout << "end" << endl;
    } else {
        cout << *iter << endl;
    }
}

int main() {
    DemoSTLAssignErase();
    DemoSortSetUnion();
    DemoMinElement();
}
