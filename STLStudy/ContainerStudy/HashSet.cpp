//
// Created by cheyulin on 7/22/16.
//
#include <iostream>
#include <unordered_set>
#include <assert.h>
#include <memory>

using namespace std;

void basic_test() {
    unordered_set<int> hash_set = {1, 4, 3, 5};
    for (auto &integer:hash_set) {
        cout << integer << endl;
    }
    cout << "size:" << hash_set.size() << endl;
    hash_set.clear();
    cout << hash_set.empty() << endl;

    hash_set.insert(8);
    hash_set.insert(2);
    hash_set.insert(8);
    hash_set.erase(8);
    cout << "size:" << hash_set.size() << endl;
    cout << *hash_set.find(2) << endl;
    for (auto integer:hash_set) {
        cout << integer << endl;
    }
    assert((hash_set.find(10) == hash_set.end()));

}

int main() {
    unordered_set<unique_ptr<int>> my_set;
    my_set.insert(make_unique<int>(1));
    my_set.insert(make_unique<int>(1));
    for(auto& int_pointer:my_set){
        cout <<*int_pointer<<endl;
    }
}
