//
// Created by cheyulin on 1/6/16.
//
#include <functional>
#include <iostream>

using namespace std;

int main() {
    function<int(int)> fib;
    fib =[&fib](int i) ->int {
        return i<2?1:fib(i-1)+fib(i-2);
    };


    cout << "Test recursive functional object:" << endl;
    for(int i=0;i<10;i++){
        cout << fib(i) << endl;
    }
}