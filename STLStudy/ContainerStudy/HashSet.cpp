//
// Created by cheyulin on 7/22/16.
//
#include <iostream>
#include <unordered_set>
#include <assert.h>
using namespace std;

int main() {
    unordered_set<int> hash_set = {1, 4, 3, 5};
    for (auto integer:hash_set) {
        cout << integer << endl;
    }
    cout << "size:"<<hash_set.size()<<endl;
    hash_set.clear();
    cout << hash_set.empty()<<endl;

    hash_set.insert(8);
    hash_set.insert(2);
    hash_set.insert(8);
    cout <<"size:"<< hash_set.size()<<endl;
    cout << *hash_set.find(2)<<endl;
    assert((hash_set.find(10)==hash_set.end()));
}
