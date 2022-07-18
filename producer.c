#include <pthread.h>
#include <stdlib.h>
#include "producer.h"
#include "fifo_chain.h"

extern pthread_mutex_t queueMutex;
extern pthread_cond_t queueCond;

void producer_process(void) {
    //First we get some new data

    Item data = rand() % 1000;
    //Lock the queue mutex to make sure that adding data to the queue happens correctly
    pthread_mutex_lock(&queueMutex);

    // Push new data to the queue
    // queue.push(newData);
    put_queue(data);

    //Signal the condition variable that new data is available in the queue
    pthread_cond_signal(&queueCond);

    //Done, unlock the mutex
    pthread_mutex_unlock(&queueMutex);
}