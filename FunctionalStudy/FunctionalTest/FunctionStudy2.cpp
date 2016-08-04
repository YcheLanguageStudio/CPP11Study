//
// Created by cheyulin on 8/4/16.
//

#include <functional>
#include <iostream>

using namespace std;

struct MyClass {
    void PrintHello() {
        //function_object() is ret_function, then we call ret_function()
        cout << "Ret:" << function_object()(1) << endl;
        //Directly call function_object2
        function_object2();
        function_object3();
    }

    //function_object hold ret_function, whole type is function<void(void)> object
    //functional programming:
    function<int(int)> function_object() {
        function<int(int)> ret_function;
        ret_function = [](int integer) -> int {
            cout << "Hello World:" << integer << endl;
            return -1;
        };
        return ret_function;
    }

    function<void()> function_object2 = []() {
        cout << "Hello World 2" << endl;
    };

    function<void()> function_object3() {
        cout << "Hello World 3" << endl;
        return [] {};
    }
};

int main() {
    MyClass().PrintHello();
    function<void(void)> function_object4 = []() {
        cout << "Hello World 4" << endl;
    };
    function_object4();
}