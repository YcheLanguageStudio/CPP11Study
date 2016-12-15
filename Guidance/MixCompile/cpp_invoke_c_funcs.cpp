//
// Created by cheyulin on 9/17/16.
//

#include <iostream>

using namespace std;

extern "C" {
int add(int a, int b);
void print();
};

int main() {
    print();
    cout << "1+2=" << add(1, 2) << endl;
}