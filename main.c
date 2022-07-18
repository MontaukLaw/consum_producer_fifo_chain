#include <stdio.h>
#include <pthread.h>
#include "fifo_chain.h"
#include "producer.h"
#include "cosumer.h"

pthread_mutex_t queueMutex;
pthread_cond_t queueCond;

int main() {
    int res;

    init_queue(maxN);

    pthread_mutex_init(&queueMutex, NULL);
    pthread_cond_init(&queueCond, NULL);

    pthread_t consumeThread,producerThread;

    res = pthread_create(&consumeThread, NULL, consume_process, NULL);
    if (res != 0) {
        printf("consume thread create failed");
        return 0;
    }

    res = pthread_create(&consumeThread, NULL, producer_process, NULL);
    if (res != 0) {
        printf("producer thread create failed");
        return 0;
    }

    return 0;
}
