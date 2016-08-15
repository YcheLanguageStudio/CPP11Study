//
// Created by cheyulin on 8/10/16.
//
#include <functional>
#include <iostream>

using namespace std;

struct Hello {
    int integer_{111};

    Hello() = default;

    Hello(int integer_) : integer_(integer_) {
        cout << "UDF:" << integer_ << endl;
        cout << endl;
    }


    Hello(const Hello &hello) {
        cout << "Copy" << endl;
    }

    Hello &operator=(const Hello &hello) {
        cout << "Copy Assignment" << endl;
    }

    Hello operator=(Hello &&hello) {
        cout << "Move Assignment" << endl;
    }

    Hello(Hello &&hello) {
        cout << "Move" << endl;
    }
};

function<Hello()> RetCopyOfFuncObj() {
    function<Hello()> function_ret_hello = nullptr;
    function_ret_hello = []() -> Hello {
        return Hello(222);
    };
    return function_ret_hello;
}

int main() {

    Hello tmp_hello1 = Hello(444);

    Hello tmp_hello = (RetCopyOfFuncObj()());
    tmp_hello = Hello(333);
    cout << endl;

    Hello *tmp_hello_ptr;
//    tmp_hello_ptr = (RetCopyOfFuncObj()());
//    if (tmp_hello_ptr != nullptr)
//        cout << tmp_hello_ptr->integer_ << endl;
}
