//
// Created by cheyulin on 4/14/16.
//
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <bits/unique_ptr.h>

using namespace std;

void test() {
    cout << "hello" << endl;
    vector<string> temp;
    temp.push_back("1");
    temp.push_back("2");
    map<int, int>::iterator it;
    queue<int> my_queue;
    my_queue.push(1);
    my_queue.push(2);

    cout << "my_queue front:" << my_queue.front() << endl;
    my_queue.pop();
    cout << "my_queue front:" << my_queue.front() << endl;

    vector<double> test_vector;
    for (auto i = 0; i < 10; ++i)
        test_vector.push_back(i);
    vector<double> test_queue;

    test_queue.assign(test_vector.begin() + 4, test_vector.end());
    test_queue.erase(test_queue.begin() + 1);

    for (auto number:test_queue) {
        cout << number << endl;
    }


    cout << test_queue.size() << endl;
}

void test_erase_pushback() {
    vector<unique_ptr<int>> vector1;
    vector<unique_ptr<int>> vector2;

    for (auto i = 0; i < 5; ++i) {
        vector1.push_back(std::move(make_unique<int>(i)));
    }

//    vector1.erase(vector1.begin()+2);

//    vector2.assign(vector1.begin()+2,vector1.end());

//    for(int hello:vector2){
//        cout <<hello;
//    }

    for (auto iter = vector1.begin() + vector1.size() / 2; iter < vector1.end(); ++iter) {
        vector2.push_back(std::move(*iter));
        vector1.erase(iter);
    }


    for (auto &&hello:vector1) {
        cout << *hello;
    }
    cout << endl << endl;
    for (auto &&hello:vector2) {
        cout << *hello;
    }
}

struct test {
    void print() {
        cout << "hello" << endl;
    }

};

void test_vector_assign_ptr() {
    vector<unique_ptr<int>> vector1;
    for (auto i = 0; i < 5; ++i) {
        vector1.push_back(std::move(make_unique<int>(i)));
    }
    vector<unique_ptr<int>> vector2;
    vector2.assign(vector1.begin() + 1, vector1.end());
    cout << vector2.size() << endl;
}

int main() {
//    test_erase_pushback();

    vector<unique_ptr<int>> vector1;
    vector<unique_ptr<int>> vector2;
    for (auto i = 0; i < 10; ++i) {
        vector1.push_back(make_unique<int>(i));
    }
    for (auto iter = vector1.begin() + 2; iter != vector1.begin() + 5; ++iter) {
        vector2.push_back(std::move(*iter));
    }
    test_vector_assign_ptr();
    getchar();
}

















