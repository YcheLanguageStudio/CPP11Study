//
// Created by cheyulin on 4/17/16.
//
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

struct Test {

    Test(int integer) : integer(integer) { }

    int integer;
};

class Class {
public:
    int hello;

    void Call() {
        vector<Test> my_vec;
        my_vec.push_back(Test(4));
        my_vec.push_back(Test(1));
        my_vec.push_back(Test(2));
        auto comp = [this](auto &left, auto &right) -> bool {
            cout << this->hello <<endl;
            return left.integer > right.integer;
        };
        sort(my_vec.begin(), my_vec.end(), comp);
        for(auto& structure:my_vec){
            cout << structure.integer<<endl;
        }
    }
};

int main() {
    Class my_class;
    my_class.hello = 111;
    my_class.Call();
    getchar();
}

