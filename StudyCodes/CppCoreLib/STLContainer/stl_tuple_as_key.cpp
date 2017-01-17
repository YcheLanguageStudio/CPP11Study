//
// Created by cheyulin on 1/17/17.
//

#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

void DemoTupleAsKey() {
    auto my_dict = map<pair<int, int>, double>{{{1, 1}, 2.0},
                                               {{2, 2}, 3.0}};
    cout << my_dict[make_pair(1, 1)] << endl;
    cout << my_dict[make_pair(1, 1)] << endl;
    cout << my_dict[make_pair(2, 2)] << endl;
    auto res = my_dict.find(make_pair(3, 3)) == my_dict.end() ? "bad" : to_string(my_dict[make_pair(3, 3)]);
    cout << res << endl;
}

int main() {
    DemoTupleAsKey();
}