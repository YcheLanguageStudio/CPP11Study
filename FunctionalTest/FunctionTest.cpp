//
// Created by cheyulin on 5/7/16.
//

#include <functional>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class TestClass {
public:
    int integer_;
    function<int()> my_function;

    TestClass(int a) : integer_(a) {
        my_function = [this]() -> int {
            cout << this->integer_ << endl;
        };
    }
};

void TestLambdaPassing() {
    TestClass my_class(1111);
    auto lambda = my_class.my_function;
    lambda();
}

void TestSort() {
    vector<unique_ptr<int>> ptr_vec;
    for (auto i = 0; i < 5; i++) {
        ptr_vec.push_back(std::move(make_unique<int>(i)));
    }
    //Failure
//    sort(ptr_vec.begin(), ptr_vec.end(), [](unique_ptr<int> &&left, unique_ptr<int> &&right) {
//        return *left > *right;
//    });
    //Okay
    sort(ptr_vec.begin(), ptr_vec.end(), [](unique_ptr<int> &left, unique_ptr<int> &right) {
        return *left > *right;
    });

    for(auto&& ptr:ptr_vec){
        cout <<*ptr<<endl;
    }
}

int main() {
    TestLambdaPassing();
    cout << endl << endl;
    TestSort();
    getchar();

}