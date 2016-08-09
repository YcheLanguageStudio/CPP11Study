//
// Created by cheyulin on 8/9/16.
//
#include <functional>
#include <iostream>
#include <assert.h>

using namespace std;

struct BreakWithCallBackRetType {
    bool is_break_{false};
    function<void(void)> call_back_function_object_{nullptr};
};

int main() {
    function<void(void)> function_object = nullptr;
    assert(function_object == nullptr);

    int integer = 0;
    function_object = [&integer]() { cout << "Hello World " << ++integer << endl; };
    bind(function_object)();

    BreakWithCallBackRetType ret;
    assert(ret.call_back_function_object_ == nullptr);
    ret.call_back_function_object_ = function_object;
    bind(ret.call_back_function_object_)();
    ret.call_back_function_object_();
}
