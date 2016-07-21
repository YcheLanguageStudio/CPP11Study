//
// Created by cheyulin on 5/7/16.
//

// condition_variable example
// From  http://www.cplusplus.com/reference/condition_variable/condition_variable/
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

using namespace std;
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

//Thread Function
void print_id(int id) {
    std::unique_lock<std::mutex> lck(mtx);
    while (!ready)
        cv.wait(lck);
    // ...
    std::cout << "thread " << id << '\n';
}

void go() {
    cout << "I am Main Thread" << endl;
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_all();
}

int main() {
    std::thread threads[10];
    // spawn 10 threads:
    // Actually They must call Thread_Create in Pthread
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(print_id, i);

    std::cout << "10 threads ready to race...\n";
    //Critical Section
    go();                       // go!

    for (auto &th : threads) th.join();

    getchar();
    return 0;
}