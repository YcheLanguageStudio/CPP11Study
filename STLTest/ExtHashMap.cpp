//
// Created by cheyulin on 7/4/16.
//

#include <ext/hash_map>
#include <iostream>

#define HASH_SPACE __gnu_cxx

int main() {
    HASH_SPACE::hash_map<int, int> hash_L2P;
    for (auto i = 0; i < 5; i++) {
        hash_L2P[i] = i + 1;
    }

    using namespace std;
    for (auto i = 0; i < 5; i++) {
        cout << hash_L2P[i] << endl;
    }
}
