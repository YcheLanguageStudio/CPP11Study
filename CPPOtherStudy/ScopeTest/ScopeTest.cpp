//
// Created by cheyulin on 4/28/16.
//
#include <iostream>

using namespace std;

class Test {
public:
    void Print() {
        static thread_local int hello_int = 0;
        hello_int++;
#pragma omp critical
        cout << hello_int << endl;
    }
};

void TestCallWithStatic(int &integer) {
    integer += 2;
    cout << integer << "!!!" << endl;
}

void TestStatic() {
    static int integer = 111;
    TestCallWithStatic(integer);

    integer++;
    cout << integer << endl;
}


int main() {
    Test test1;
#pragma omp parallel for
    for (auto i = 0; i < 5; i++) {
        test1.Print();
    }
    Test test2;

#pragma omp parallel for
    for (auto j = 0; j < 5; j++) {
        test2.Print();
    }


    for (auto i = 0; i < 5; i++)
        TestStatic();

    getchar();
}