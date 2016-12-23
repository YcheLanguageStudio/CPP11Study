//
// Created by cheyulin on 7/22/16.
//
//
#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include <cassert>

#include "../../Utilities/pretty_print.h"

using namespace std;

void DemoHashMap() {
    auto my_map = unordered_map<int, string>{{1, "one"},
                                             {2, "two"},
                                             {3, "three"}};
    cout << my_map << endl;
    my_map[2] = "changed";
    cout << my_map << endl;
}

void DemoHashSet() {
    auto hash_set = unordered_set<int>{1, 4, 3, 5};
    cout << hash_set << endl;
    hash_set.emplace(8);
    hash_set.emplace(4);
    hash_set.emplace(8);
    assert(hash_set.find(4) != hash_set.end());
    cout << hash_set << endl;
}

void DemoPair() {
    auto my_vector=vector<pair<string, string>>(100);
    cout << my_vector << endl;
}

int main() {
    DemoPair();
    DemoHashMap();
    DemoHashSet();
}
