//
// Created by cheyulin on 4/16/16.
//

#include <memory>
#include <set>
#include <iostream>

using namespace std;

//If unique_ptr<int> implement move assignment constructor
//Call callfunction(std::move(xxx))
//Will call the move assignment constructor
int callfunction(unique_ptr<int> int_ptr) {
    cout << "In Function:" << *int_ptr << endl;
    return -1;
}

//If set<int> implement move assignment constructor
//Call callfunction2(std::move(xxx))
//Will call the move assignment constructor
void callfunction2(set<int> set_r_val) {
    for (auto integer:set_r_val) {
        cout << integer << ",";
    }
    cout << endl;
}


int main() {
    set<int> first_set;
    first_set.insert(1);
    first_set.insert(2);
    //use The Rvalue Assignment Constructor
    auto second_set = std::move(first_set);
    cout << second_set.size() << endl;
    cout << first_set.size() << endl;

    auto int_ptr = make_unique<int>(1);
    cout << "!!" << (int_ptr == nullptr) << endl;

    callfunction(std::move(int_ptr));
    cout << "!!" << (int_ptr == nullptr) << endl;

    callfunction2(std::move(second_set));
    cout << second_set.size() << endl;
    getchar();


}