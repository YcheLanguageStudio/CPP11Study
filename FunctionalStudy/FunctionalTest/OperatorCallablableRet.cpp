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
    }


    Hello(const Hello &hello) {
        cout << "Copy" << endl;
    }

    Hello(Hello &&hello) {
        cout << "Move" << endl;
    }
};

int main() {
    function<Hello()> function_ret_hello = nullptr;
    function_ret_hello = []() -> Hello {
        return Hello(222);
    };

    Hello tmp_hello = (function_ret_hello());
//    tmp_hello = std::move(Hello(333));
//    Hello *tmp_hello_ptr = nullptr;
//    *tmp_hello_ptr = function_ret_hello();
//    cout << tmp_hello_ptr->integer_ << endl;
}
