//
// Created by cheyulin on 8/5/16.
//
#include <boost/thread/thread.hpp>
#include <iostream>
#include <boost/thread/once.hpp>
#include <boost/thread/scoped_thread.hpp>

using namespace boost;
using namespace std;

int g_count;

void init_count(int x) {
    cout << "should call once" << endl;
    g_count = x;
}

void call_func() {
    static once_flag once;
    call_once(once, init_count, 10);
}

int main() {
    (scoped_thread<>(call_func));
    (scoped_thread<>(call_func));
    cout << g_count << endl;
}