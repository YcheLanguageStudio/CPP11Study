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


int main(int argc, char *argv[]) {
    long thread;
    pthread_t *thread_handles;
    /* Get number of threads from command line*/
    thread_count = strtol(argv[1], NULL, 10);
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
    getchar();
    return 0;

}

