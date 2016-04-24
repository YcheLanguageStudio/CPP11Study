//
// Created by cheyulin on 4/24/16.
//

//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <semaphore.h>

using namespace std;
int thread_count;
int count;
pthread_mutex_t mutex;
sem_t count_sem;
sem_t barrier_sem;

void *Thread_work(void *rank) {
    struct timespec begin, end;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    sleep((long) rank);
    pthread_mutex_lock(&mutex);
    count++;
    pthread_mutex_unlock(&mutex);
    while (count < thread_count);
    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = end.tv_sec - begin.tv_sec;
    elapsed += (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    pthread_mutex_lock(&mutex);
    cout << "Thread " << (long) rank << "Elaspsed Time:" << elapsed << endl;
    pthread_mutex_unlock(&mutex);

}

void RunWithMutex() {
    long thread;
    pthread_t *thread_handles;

    /* Get number of threads from command line*/
    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));

    count = 0;
    pthread_mutex_init(&mutex, NULL);

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Thread_work, (void *) thread);
    }

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    pthread_mutex_destroy(&mutex);
    free(thread_handles);
    getchar();
}

void *Thread_work_PV_Operation(void *rank) {
    struct timespec begin, end;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    sleep((long) rank);

    //Lock
    sem_wait(&count_sem);
    if (count == thread_count - 1) { //Last One
        count = 0;
        sem_post(&count_sem);
        for (auto i = 0; i < thread_count - 1; i++)
            sem_post(&barrier_sem);
    } else {
        // Before Last One
        count++;
        //Unlock
        sem_post(&count_sem);
        sem_wait(&barrier_sem);
    }


    clock_gettime(CLOCK_MONOTONIC, &end);
    elapsed = end.tv_sec - begin.tv_sec;
    elapsed += (end.tv_nsec - begin.tv_nsec) / 1000000000.0;
    pthread_mutex_lock(&mutex);
    cout << "Thread " << (long) rank << "Elaspsed Time:" << elapsed << endl;
    pthread_mutex_unlock(&mutex);

}

void RunWithSemaphore() {
    long thread;
    pthread_t *thread_handles;

    /* Get number of threads from command line*/
    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));

    sem_init(&count_sem, NULL, 1);
    sem_init(&barrier_sem, NULL, 0);

    count = 0;

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Thread_work_PV_Operation, (void *) thread);
    }

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    sem_destroy(&count_sem);
    sem_destroy(&barrier_sem);

    free(thread_handles);
    getchar();
}


int main(int argc, char *argv[]) {
    thread_count = strtol(argv[1], NULL, 10);
//    RunWithMutex();
    RunWithSemaphore();
    return 0;

}