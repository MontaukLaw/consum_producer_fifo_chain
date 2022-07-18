#include <stdio.h>
#include <pthread.h>
#include "fifo_chain.h"

pthread_mutex_t queueMutex;
pthread_cond_t queueCond;

int main() {
    init_queue(maxN);

    pthread_mutex_init(&queueMutex, NULL);
    pthread_cond_init(&queueCond, NULL);

    return 0;
}
