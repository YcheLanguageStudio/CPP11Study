//
// Created by cheyulin on 4/24/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <semaphore.h>

#define  MAX_MSG_SIZE 20
using namespace std;

long thread_count;
char **message_cyl;
sem_t *semaphores;

void *Send_msg(void *rank) {
    long my_rank = (long) rank;
    long dest = (my_rank + 1) % thread_count;
    long source = (my_rank - 1 + thread_count) % thread_count;
    char *my_msg = (char *) malloc(MAX_MSG_SIZE * sizeof(char));

    sprintf(my_msg, "Hello to %ld from %ld", dest, my_rank);
    message_cyl[dest] = my_msg;
    if (message_cyl[my_rank] != NULL) {
        cout << "Thread" << my_rank << " " << message_cyl[my_rank] << endl;
    }
    else {
        cout << "No Message from " << source << endl;
    }
}

void RunWithNoWaiting() {
    long thread;
    pthread_t *thread_handles;
    message_cyl = new char *[thread_count];
    for (auto i = 0; i < thread_count; ++i) {
        message_cyl[i] = NULL;
    }
    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Send_msg, (void *) thread);
    }
    cout << "Hello from the main thread" << endl;

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }
    free(thread_handles);
    free(message_cyl);
}

void *Send_msg_semaphore(void *rank) {
    long my_rank = (long) rank;
    long dest = (my_rank + 1) % thread_count;
    char *my_msg = (char *) malloc(MAX_MSG_SIZE * sizeof(char));

    sprintf(my_msg, "Hello to %ld from %ld", dest, my_rank);

    message_cyl[dest] = my_msg;
    sem_post(&semaphores[dest]);

    sem_wait(&semaphores[my_rank]);
    cout << "Thread " << my_rank << " Msg:" << message_cyl[my_rank] << endl;
}

void RunWithSemaphore() {
    long thread;
    pthread_t *thread_handles;
    message_cyl = new char *[thread_count];
    for (auto i = 0; i < thread_count; ++i) {
        message_cyl[i] = NULL;
    }

    semaphores = (sem_t *) malloc(thread_count * sizeof(sem_t));
    for (auto i = 0; i < thread_count; i++) {
        sem_init(&semaphores[i], 0, 0);
    }

    //Run Threads
    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Send_msg_semaphore, (void *) thread);
    }
    cout << "Hello from the main thread" << endl;

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }


    for (auto i = 0; i < thread_count; ++i) {
        sem_destroy(&semaphores[i]);
    }

    free(semaphores);
    free(message_cyl);
}

int main(int argc, char *argv[]) {
    /* Get number of threads from command line*/
    thread_count = strtol(argv[1], NULL, 10);
    RunWithNoWaiting();

    cout << endl << endl;

    RunWithSemaphore();
    getchar();
    return 0;

}