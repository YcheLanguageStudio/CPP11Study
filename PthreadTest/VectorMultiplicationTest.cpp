//
// Created by cheyulin on 4/24/16.
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>

using namespace std;
int thread_count;
int m;
int n;
double *y;
double *x;
/*Vector*/
double **A;

/*Matrix*/

void *Pth_mat_vect(void *rank) {
    cout << "computation" << endl;
    long my_rank = (long) rank;
    int i, j;
    int local_m = m / thread_count;
    int my_first_row = (my_rank * local_m);
    int my_last_row = (my_rank + 1) * local_m - 1;

    cout << my_first_row <<"," << my_last_row;
    for (i = my_first_row; i <= my_last_row; i++) {
        y[i] = 0;
        for (j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    return NULL;
}


int main(int argc, char *argv[]) {
    long thread;
    pthread_t *thread_handles;
    m = 4;
    n = 4;
    A = new double *[m];
    for (auto i = 0; i < m; i++) {
        A[i] = new double[n];
        for (auto j = 0; j < n; j++) {
            A[i][j] = j + 1;
        }
    }

    x = new double[n];
    for (auto i = 0; i < n; i++) {
        x[i] = i * i + 1;
    }

    for (auto i = 0; i < m; i++) {
        for (auto j = 0; j < n; j++) {
            cout << i << "," << j << "  " << A[i][j] << endl;
        }
    }
    for(auto i=0;i<n;i++){
        cout <<"xi "<<i<<" "<<x[i]<<endl;
    }
    /* Get number of threads from command line*/
    thread_count = strtol(argv[1], NULL, 10);
    cout << "pthread_t size:" << sizeof(pthread_t) << endl;

    thread_handles = (pthread_t *) malloc(thread_count * sizeof(pthread_t));

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void *) thread);
    }
    cout << "Hello from the main thread" << endl;

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }
    free(thread_handles);
    getchar();
    return 0;

}
