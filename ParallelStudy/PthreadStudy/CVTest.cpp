//
// Created by cheyulin on 5/8/16.
//

//From http://blog.csdn.net/hairetz/article/details/4535920#

#include <pthread.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

struct node {
    int n_number;
    struct node *n_next;
} *head = NULL;

/*[thread_func]*/
static void cleanup_handler(void *arg) {
    printf("Cleanup handler of second thread.\n");
    free(arg);
    (void) pthread_mutex_unlock(&mtx);
}

static void *thread_func(void *arg) {
    struct node *p = NULL;

    while (true) {
        pthread_cleanup_push(cleanup_handler, p);
            pthread_mutex_lock(&mtx);
            while (head == NULL) {
                pthread_cond_wait(&cond, &mtx);
            }
            p = head;
            head = head->n_next;
            printf("Got %d from front of queue\n", p->n_number);
            std::cout << std::endl;
            free(p);
            pthread_mutex_unlock(&mtx);             //临界区数据操作完毕，释放互斥锁
        pthread_cleanup_pop(0);
    }

    return 0;
}

int main(void) {
    pthread_t tid;
    int i;
    struct node *p;
    pthread_create(&tid, NULL, thread_func, NULL);
    //子线程会一直等待资源，类似生产者和消费者，但是这里的消费者可以是多个消费者，而不仅仅支持普通的单个消费者，这个模型虽然简单，但是很强大

    /*[tx6-main]*/
    for (i = 0; i < 100000; i++) {
        p = (node *) malloc(sizeof(struct node));
        p->n_number = i;
        pthread_mutex_lock(&mtx);
        p->n_next = head;
        head = p;
        pthread_cond_broadcast(&cond);
        pthread_mutex_unlock(&mtx);
//        sleep(1);
    }

    printf("thread 1 wanna end the line.So cancel thread 2.\n");
    std::cout << std::endl;
    pthread_cancel(tid);
    //关于pthread_cancel，有一点额外的说明，它是从外部终止子线程，子线程会在最近的取消点，退出线程，而在我们的代码里，最近的取消点肯定就是pthread_cond_wait()了。关于取消点的信息，有兴趣可以google,这里不多说了
    pthread_join(tid, NULL);
    printf("All done -- exiting/n");
    getchar();
    return 0;
}