//
// Created by cheyulin on 8/13/16.
//
#include <vector>

#include <iostream>

using namespace std;

int main() {
    vector<pair<string, string>> my_vector{100};

    for (auto &my_pair:my_vector) {
        if (&my_pair != nullptr)
            cout << my_pair.first.size() << "," << my_pair.second.size() << endl;
    }
}