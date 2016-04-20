//
// Created by cheyulin on 4/10/16.
//
#include<memory>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class TestClass {
public:
    unique_ptr<int> test_uptr_;

    TestClass(unique_ptr<int> &test_uptr) {
        test_uptr_ = std::move(test_uptr);
        cout << "test_uptr" << *test_uptr_ << endl;
    }
};

unique_ptr<int> test_unique_ptr_input(unique_ptr<int> in_ptr) {
    *in_ptr = 4;
    return move(in_ptr);
}


struct Class {

    Class(int integer) : integer(integer) { }

    Class(const Class &input) {
        this->integer = input.integer;
    }

    int integer;
};

struct Class2 {
    int shit;
    double w1;
    double w2;

    Class2(int integer) : shit(integer) { }

    bool operator==(const Class2 &another) {
        return another.shit == this->shit;
    }

};

int main() {
//    unique_ptr<int> u_ptr4;
//    unique_ptr<int> u_ptr2(new int(2));
//    cout << *u_ptr2 << endl;
//    *u_ptr2 = 1;
//    cout << *u_ptr2 << endl ;
//
//    unique_ptr<int> u_ptr1 = std::move(u_ptr2);
//    cout << *u_ptr1 << endl ;
//
//    unique_ptr<int> u_ptr3 = std::move(u_ptr1);
//    cout << *u_ptr3 << endl ;
//
//    TestClass myclass(u_ptr3);
//    u_ptr4 = std::move(myclass.test_uptr_);
//    cout << "u_ptr4:" << *u_ptr4;

//    vector<int>* v_p = new vector<int>();
//    unique_ptr<vector<int>> my_set_ptr(v_p);
    //Make Unique Specify Template Type
    unique_ptr<vector<int>> my_set_ptr = make_unique<vector<int>>();
    my_set_ptr->push_back(1);
    for (auto iter = my_set_ptr->begin(); iter != my_set_ptr->end(); ++iter) {
        cout << "iter:" << *iter << endl;
    }

    cout << endl << endl;
    unique_ptr<int> former_ptr = make_unique<int>(3);
    former_ptr = test_unique_ptr_input(std::move(former_ptr));
    cout << ">>:" << *former_ptr << endl;

    auto comp = [](auto &&left, auto &&right) {
        return left->integer < right->integer;
    };
    set<unique_ptr<Class>, decltype(comp)> my_set(comp);
    my_set.insert(std::move(make_unique<Class>(2)));
    my_set.insert(std::move(make_unique<Class>(3)));
    my_set.insert(std::move(make_unique<Class>(4)));

    cout << endl << endl;
    for (auto &&ptr: my_set) {
        cout << "haha:" << ptr->integer << endl;
    }

    vector<unique_ptr<Class>> my_vec;
    for (auto &&ptr : my_set) {
        my_vec.push_back(make_unique<Class>(*ptr));
    }

    sort(my_vec.begin(), my_vec.end(), [](auto &&l_ptr, auto &&r_ptr) { return l_ptr->integer > r_ptr->integer; });
    for (auto &&ptr:my_vec) {
        cout << "hehe:" << ptr->integer << endl;
    }

    cout << endl << endl;
    auto comp2 = [](auto &&left, auto &&right) -> bool { return left->shit > right->shit; };
    set<unique_ptr<Class2>, decltype(comp2)> class2_set(comp2);
    class2_set.insert(std::move(make_unique<Class2>(1)));
    class2_set.insert(std::move(make_unique<Class2>(2)));
    class2_set.insert(std::move(make_unique<Class2>(3)));

    class2_set.erase(std::move(make_unique<Class2>(2)));
    for (auto &&ptr:class2_set) {
        cout << ptr->shit << endl;
    }
    if(class2_set.find(std::move(make_unique<Class2>(3)))!= class2_set.end()){
        cout <<"dfsfdsfdsklgfdsgl"<<endl;
    }
    getchar();


}






