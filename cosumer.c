#include <pthread.h>
#include <stdio.h>
#include "cosumer.h"
#include "fifo_chain.h"

extern pthread_mutex_t queueMutex;
extern pthread_cond_t queueCond;

void consume_process(void *arg) {
    Item data;
    // Run the consumer loop
    while(1) {

        // Start by locking the queue mutex
        pthread_mutex_lock(&queueMutex);

        // As long as the queue is empty,
        while(is_queue_empty()) {
            // - wait for the condition variable to be signalled
            // Note: This call unlocks the mutex when called and
            // relocks it before returning!
            pthread_cond_wait(&queueCond, &queueMutex);
        }

        // Consume data
        data = get_new_item();

        //Now unlock the mutex
        pthread_mutex_unlock(&queueMutex);

        // - and process the new data
        printf("Get: %d\n", data);

        // ProcessData(newData);
    }
}


