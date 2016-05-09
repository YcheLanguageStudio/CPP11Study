//
// Created by cheyulin on 5/9/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <semaphore.h>
#include <vector>

int thread_count;
pthread_mutex_t mutex;
pthread_cond_t cond_var;
int idle_count = 0;
using namespace std;
vector<int> global_vec;
bool is_end = false;

void *ThreadFunction(void *thread_label) {
    long thread_id = (long) thread_label;

    long local_result = 1;
    while (!is_end) {
        pthread_mutex_lock(&mutex);
        global_vec.push_back(local_result);
        if (global_vec.size() >= 2) {
            vector<int> local_vec;
            for (auto i = 0; i < 2; i++) {
                local_vec.push_back(global_vec.back());
                global_vec.erase(global_vec.end() - 1);
            }
            pthread_mutex_unlock(&mutex);
            //Do the computation After release the lock
            local_result = 0;
            for (auto integer:local_vec) {
                local_result += integer;
            }
        }
        else {
            if (idle_count == thread_count - 1) {
                is_end = true;
                pthread_cond_broadcast(&cond_var);
            }
            else {
                idle_count++;
                while (pthread_cond_wait(&cond_var, &mutex) != 0);
            }
            pthread_mutex_unlock(&mutex);

        }
    }
#pragma omp critical
    cout << "Thread " << thread_id << " ready to exit" << endl;

    return NULL;
}

int main(int argc, char *argv[]) {
    thread_count = strtol(argv[1], NULL, 10);
    long thread;
    pthread_t *thread_handles;

    /* Get number of threads from command line*/
    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_var, NULL);
    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, ThreadFunction, (void *) thread);
    }

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_var);
    free(thread_handles);


    cout << "Global sum:" << global_vec[0] << endl;
    getchar();

    return 0;

}