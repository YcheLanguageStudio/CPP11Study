//
// Created by cheyulin on 12/16/16.
//
// Originally From https://gist.github.com/sguzman/9594227

#include <mutex>
#include <condition_variable>

using namespace std;

class Semaphore {
public:
    Semaphore(int count = 0) : count_(count) {}

    void notify() {
        unique_lock<mutex> lck(mtx_);
        ++count_;
        cv_.notify_one();
    }

    void wait() {
        unique_lock<mutex> lck(mtx_);
        while (count_ == 0) {
            cv_.wait(lck);
        }
        --count_;
    }

private:
    mutex mtx_;
    condition_variable cv_;
    int count_;
};