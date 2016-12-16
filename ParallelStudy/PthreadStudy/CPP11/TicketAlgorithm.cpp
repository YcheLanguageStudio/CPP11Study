//
// Created by cheyulin on 12/16/16.
//

//Originally From http://alexmeuer.github.io/2016/07/12/ticket-algorithm.html

#include <iostream>
#include <atomic>
#include <thread>
#include <mutex>
#include <sstream>
#include <functional>
#include <algorithm>

using namespace std;

constexpr int n = 10;
atomic_int number;
atomic_int next_number;
atomic_int turn_number[n];
int thread_nums;
mutex coutMutex;

ostringstream data;

void func() {
    int i = thread_nums++;  //Intentional post-increment

    coutMutex.lock();
    cout << "Thread " << i << " reporting in." << endl;
    coutMutex.unlock();

    this_thread::sleep_for(chrono::milliseconds(rand() % 500 + 500));

    for (auto i = 0; i < 1000; i++) {
        //Take a ticket
        turn_number[i] = number.fetch_add(1);

        coutMutex.lock();
        cout << "t" << i << "\tturn: " << turn_number[i] << endl;
        coutMutex.unlock();

        this_thread::sleep_for(chrono::milliseconds(rand() % 500 + 500));

        while (turn_number[i] != next_number) {
            continue;
        }

        coutMutex.lock();
        cout << "t" << i << "\t+CS" << endl;
        coutMutex.unlock();

        //critical section
        data << " data_t" << i;

        //exit protocol
        next_number += 1;

        coutMutex.lock();
        cout << data.str() << endl;
        cout << "t" << i << "\tnext = " << next_number << endl;
        coutMutex.unlock();
    }
}


int main(int argc, char *argv[]) {
    srand(static_cast<unsigned int>(time(NULL)));

    data = ostringstream();

    thread_nums = 0;
    number = 1;
    next_number = 1;

    for (int i = 0; i < n; i++) {
        turn_number[i] = 0;
    }

    thread t1 = thread(func);
    thread t2 = thread(func);

    t1.join();
    t2.join();

    return 0;
}