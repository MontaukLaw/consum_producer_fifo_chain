#ifndef FIFO_CHAIN_FIFO_CHAIN_H
#define FIFO_CHAIN_FIFO_CHAIN_H

typedef struct Node Node;
typedef Node *Queue;
typedef int Item;
static int maxN = 10;

void init_queue(int maxN);
void put_queue(Item item);
Item get_new_item(void);
int is_queue_empty(void);

#endif //FIFO_CHAIN_FIFO_CHAIN_H
