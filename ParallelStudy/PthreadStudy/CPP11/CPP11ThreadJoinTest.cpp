//
// Created by cheyulin on 5/7/16.
//

#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable

void ThreadFunction(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 * id));
}

void TestThreadCreateJoin() {
    //Similar to Thread Handles in Pthread
    struct timespec begin, *end;
    end = new timespec[10];
    clock_gettime(CLOCK_MONOTONIC, &begin);
    std::thread threads[10];
    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(ThreadFunction, i);

    std::cout << "10 threads have been spawned...\n";

    for (auto i = 0; i < 10; i++) {
        auto &th = threads[i];
        th.join();
        clock_gettime(CLOCK_MONOTONIC, &end[i]);
        auto elapsed = end[i].tv_sec - begin.tv_sec;
        elapsed += (end[i].tv_nsec - begin.tv_nsec) / 1000000000.0;
        std::cout << "Suspend thread " << i << " at " << elapsed << std::endl;
    }

    std::cout << "All Work Finished" << std::endl;
}

int main() {
    TestThreadCreateJoin();
}
