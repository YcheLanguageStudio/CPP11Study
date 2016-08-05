//
// Created by cheyulin on 8/4/16.
//

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void thread_function(int thread_id) {
#pragma omp critical
    cout << "Hello World From Worker" << thread_id << endl;
}

int main() {
    constexpr int THREAD_NUM = 10;
    vector<thread> thread_vector;
    //Fork Workers
    for (auto i = 0; i < THREAD_NUM; i++) {
        thread_vector.emplace_back(thread_function, i);
    }

    cout << "Master Thread Watiting for Workers Exit and Ready for Join" << endl;

    //    Join Workers
    for (auto i = 0; i < THREAD_NUM; i++) {
        if (thread_vector[i].joinable())
            thread_vector[i].join();
    }
}