//
// Created by cheyulin on 4/16/16.
//

#include <memory>
#include <set>
#include <iostream>
using namespace std;
int main(){
    set<int> first_set;
    first_set.insert(1);
    first_set.insert(2);
    //use The Rvalue Assignment Constructor
    auto second_set = std::move(first_set);
    cout << second_set.size() << endl;
    cout << first_set.size() << endl;
    getchar();
}