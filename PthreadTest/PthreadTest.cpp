//
// Created by cheyulin on 4/24/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>

using namespace std;
int thread_count;

/*Shared By All Threads*/

void *Hello(void *rank);

/*Thread Function*/

int main(int argc, char *argv[]) {
    long thread;
    pthread_t *thread_handles;

    /* Get number of threads from command line*/
    thread_count = strtol(argv[1], NULL, 10);
    cout << "pthread_t size:" << sizeof(pthread_t) << endl;
    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Hello, (void *) thread);
    }
    cout << "Hello from the main thread" << endl;

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }
    free(thread_handles);
    getchar();
    return 0;

}


void *Hello(void *rank) {
    long my_rank = (long) rank;
    cout << "Hello From Thread " << my_rank << " Of " << thread_count << endl;
    return NULL;
}