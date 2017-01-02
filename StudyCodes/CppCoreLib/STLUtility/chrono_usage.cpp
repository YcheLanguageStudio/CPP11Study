//
// Created by cheyulin on 12/28/16.
//

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long fibonacci(unsigned n) {
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void DemoBasicDuration() {
    time_point<system_clock> start, end;
    start = system_clock::now();
    cout << "f(42) = " << fibonacci(42) << '\n';
    end = system_clock::now();

    duration<double> elapsed_seconds = end - start;
    time_t end_time = system_clock::to_time_t(end);

    cout << "finished computation at " << ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

void DemoDurationCast() {
    auto t0 = high_resolution_clock::now();
    cout << "f(42) = " << fibonacci(42) << '\n';
    auto t1 = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(t1 - t0).count() << "ms" << endl;
}

int main() {
    DemoBasicDuration();
    DemoDurationCast();
}