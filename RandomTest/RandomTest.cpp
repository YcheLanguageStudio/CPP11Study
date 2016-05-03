//
// Created by cheyulin on 4/28/16.
//
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

void GenerateRandom() {
    static thread_local random_device rand_d;
    static thread_local std::mt19937 gen(rand_d());
    uniform_int_distribution<> dis(1, 6);
#pragma omp critical
    {
        for (auto i = 0; i < 10; i++) {
            cout << dis(gen) << ",";
        }
        cout << endl;
    }
}

void TestRandomNumGen() {
#pragma parallel omp for
    for (auto i = 0; i < 20; i++) {
        GenerateRandom();
    }
}

void LocalShuffle() {
    static thread_local random_device rand_d;
    static thread_local std::mt19937 gen(rand_d());
    vector<int> my_vector;

    for (auto i = 0; i < 10; i++) {
        my_vector.push_back(i);
    }
    shuffle(my_vector.begin(), my_vector.end(), gen);

#pragma omp critical
    {
        for (auto integer:my_vector) {
            cout << integer << ",";
        }
        cout << endl;
    }
}

void TestRandomShuffle() {
#pragma parallel omp for
    for (auto i = 0; i < 20; i++) {
        LocalShuffle();
    }
}

int main() {
    TestRandomNumGen();
//    TestRandomShuffle();
    getchar();
}
