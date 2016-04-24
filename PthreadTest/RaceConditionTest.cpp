//
// Created by cheyulin on 4/24/16.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>

using namespace std;
int thread_count;
long long n = 10000000;
double sum = 0;
long long flag = 0;
pthread_mutex_t mutex;

void *Thread_sum(void *rank) {
    cout << "Thread:" << rank << endl;
    double my_sum = 0;
    double factor;
    long my_rank = (long) rank;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_n * (my_rank + 1);

    cout << "first_i" << my_first_i << endl;
    if (my_first_i & 2 == 0)
        factor = 1;
    else
        factor = -1;

    for (long long i = my_first_i; i < my_last_i; i++, factor = -factor) {
        my_sum += factor / (2 * i + 1);
    }

    //Critical Section
    //Busy Waiting
    while (flag != my_rank);
    sum += my_sum;
    flag = (flag + 1) % thread_count;

    cout << "Thread:" << rank << "finished" << endl;
    return NULL;
}

void *Thread_sum_mutex(void *rank) {
    cout << "Thread:" << rank << endl;
    double my_sum = 0;
    double factor;
    long my_rank = (long) rank;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_n * (my_rank + 1);

    cout << "first_i" << my_first_i << endl;
    if (my_first_i & 2 == 0)
        factor = 1;
    else
        factor = -1;

    for (long long i = my_first_i; i < my_last_i; i++, factor = -factor) {
        my_sum += factor / (2 * i + 1);
    }

    //Critical Section
    //Mutex
    pthread_mutex_lock(&mutex);
    sum += my_sum;
    pthread_mutex_unlock(&mutex);
    flag = (flag + 1) % thread_count;

    cout << "Thread:" << rank << "finished" << endl;
    return NULL;
}

void RunWithBusyWaiting() {
    long thread;
    pthread_t *thread_handles;
    /* Get number of threads from command line*/

    cout << "pthread_t size:" << sizeof(pthread_t) << endl;
    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void *) thread);
    }
    cout << "Hello from the main thread" << endl;

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }
    free(thread_handles);

    cout << sum << endl;
}

void RunWithMutex() {
    cout << "Hi" << endl;
    long thread;
    pthread_t *thread_handles;
    /* Get number of threads from command line*/

    cout << "pthread_t size:" << sizeof(pthread_t) << endl;
    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Thread_sum_mutex, (void *) thread);
    }
    cout << "Hello from the main thread" << endl;

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }
    free(thread_handles);

    cout << sum << endl;
}

int main(int argc, char *argv[]) {
    thread_count = strtol(argv[1], NULL, 10);

    struct timespec begin, end;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &begin);
// spawn threads to do work here
    RunWithBusyWaiting();
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = end.tv_sec - begin.tv_sec;
    elapsed += (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    cout << "Elapsed Time:" << elapsed << endl;
    cout << endl << endl;

    sum = 0;
    flag = 0;
    cout << "Before" << endl;

    pthread_mutex_init(&mutex, NULL);
    cout << "Init Mutex" << endl;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    RunWithMutex();
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = end.tv_sec - begin.tv_sec;
    elapsed += (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    cout << "Elapsed Time:" << elapsed << endl;
    cout << endl << endl;
    pthread_mutex_destroy(&mutex);
    getchar();
    return 0;

}

