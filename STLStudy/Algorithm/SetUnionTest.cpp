//
// Created by cheyulin on 7/21/16.
//
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    vector<int> v1 = {1, 4, 2, 6};
    vector<int> v2 = {8, 1, 2, 7, 3};
    vector<int> v3;
    vector<int> v4;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    v3.resize(v1.size() + v2.size());
    auto iter_end = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    v3.resize(iter_end - v3.begin());

    for (auto integer:v3) {
        cout << integer << ", ";
    }
    cout << endl;

    v4.resize(v1.size() + v2.size());
    iter_end = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    v4.resize(iter_end - v4.begin());

    for (auto integer:v4) {
        cout << integer << ", ";
    }
    cout << endl;
}
