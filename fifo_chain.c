#include <stddef.h>
#include <malloc.h>
#include "fifo_chain.h"

struct Node //节点结构
{
    Item item;
    Node *next;
};

static Queue q = NULL;
static Node *tail = NULL;

// 新建一个节点
Node *new_node(Item item, Node *Next) // Next为插入的后一节点
{
    Node *x = (Node *) malloc(sizeof(*x));//被插入的节点
    x->item = item;
    x->next = Next;
    return x;
}

// 队列初始化
void init_queue(int maxN) {
    q = NULL;
}

// 判断队列是否为空
int is_queue_empty(void) {
    return (q == NULL);
}

// put操作
void put_queue(Item item) {
    if (is_queue_empty()) {
        q = (tail = new_node(item, q));
    } else {
        tail->next = new_node(item, tail->next);
        tail = tail->next;
    }
    printf("Put: %d\n", item);
}

// get操作
Item get_new_item(void) {
    if (q == NULL) {
        printf("Empty chain list！\n");
        return -1;
    }

    Item firstItem = q->item;//序列的头元素
    Node *tmpNode = q;
    q = q->next;
    free(tmpNode);
    return firstItem;
}

void chain_list_test(void) {
    init_queue(maxN);

    put_queue(2);
    put_queue(3);
    put_queue(4);

    printf("\n");

    printf("Get: %d\n", get_new_item());
    printf("Get: %d\n", get_new_item());
    printf("Get: %d\n", get_new_item());
    printf("Get: %d\n", get_new_item());

}