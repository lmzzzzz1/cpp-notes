#ifndef QUEUE_H_
#define QUEUE_H_
#define ANY_LENGTH
#define true 1
#define false 0
typedef short bool;
#define MAXQUEUE 10

typedef struct film
{
    int rating;
    char name[];
} Item1;

typedef int Item;
typedef struct node{
    Item item;
    struct node *next;
}Node;

typedef struct queue
{
    Node *front;
    Node *end;
    int length;
} Queue;

/* 对外接口 */
void InitializeQueue(Queue *q); /* 初始化 */
bool QueueisFull(const Queue *q);
bool QueueIsEmpty(const Queue *q);

int QueueItemCount(const Queue *q);
bool EnQueue(Item item, Queue *q);

bool DeleteQueue(Queue *q, Item *item);
void EmptyTheQueue(Queue *q);


#endif