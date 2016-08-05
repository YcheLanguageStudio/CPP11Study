//
// Created by cheyulin on 8/5/16.
//

#include<stack>
#include <iostream>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/lock_factories.hpp>
#include <boost/thread/thread.hpp>

using namespace boost;
using namespace std;

class buffer {
private:
    //Used For the protection of global shared buffer
    mutex mu;
    condition_variable_any cond_put;
    condition_variable_any cond_get;

    stack<int> stk;
    int un_read, capacity;

    bool is_full() {
        return un_read == capacity;
    }

    bool is_empty() {
        return un_read == 0;
    }

public:
    buffer(int capacity) : un_read(0), capacity(capacity) {}

    void put(int x) {
        //Scope of usage of mutex_lock RAII, following instruction section is protected with mu
        {
            auto lock = make_unique_lock(mu);
            for (; is_full();) {
                cout << "Full Waiting" << endl;
                cond_put.wait(lock);
            }
            stk.push(x);
            ++un_read;
        }
        //After push into buffer, consumer could consume that
        cond_get.notify_one();
    }

    void get(int *x) {
        //Scope of usage of mutex_lock RAII, following instruction section is protected with mu
        {
            auto lock = make_unique_lock(mu);
            for (; is_empty();) {
                cout << "empty waiting" << endl;
                cond_get.wait(lock);
            }
            --un_read;
            *x = stk.top();
            stk.pop();
        }
        //Since pop from buffer, producer could put into the un-empty buffer
        cond_put.notify_one();
    }
};

buffer buf(5);

void producer(int n) {
    cout << "n:" << n << endl;
    for (auto i = 0; i < n; ++i) {
        cout << "put " << i << endl;
        buf.put(i);
    }
}

void consumer(int n) {
    int x;
    for (auto i = 0; i < n; ++i) {
        buf.get(&x);
        cout << "get " << x << endl;
    }
}

int main() {
    thread_group tg;
    tg.create_thread(bind(consumer, 30));

    tg.create_thread(bind(producer, 10));
    tg.create_thread(bind(producer, 10));
    tg.create_thread(bind(producer, 10));

    tg.join_all();
}


