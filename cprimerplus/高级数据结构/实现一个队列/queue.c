#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void InitializeQueue(Queue *q)
{
    q->front = q->end = NULL;
    q->length = 0;
}

bool QueueisFull(const Queue *q)
{
    return q->length == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *q)
{
    return q->length == 0;
}

int QueueItemCount(const Queue *q)
{
    return q->length;
}

bool EnQueue(Item item, Queue *q)
{
    Node *newNode =  (Node *)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        fprintf(stderr, "No mem error!\n");
        exit(1);
    }
    newNode->item = item;
    newNode->next = NULL;
    if (QueueIsEmpty(q))
        q->front = newNode;
    else
        q->end->next = newNode;
    q->length++;
    q->end = newNode;
    return true;
}

bool DeleteQueue(Queue *q, Item *item)
{
    Node *pt;
    if(QueueIsEmpty(q))
        return false;
    *item = q->front->item;
    pt = q->front;
    q->front = q->front->next;
    free(pt);
    q->length--;
    if(q->length==0)
        q->end=NULL;
    return true;
}

void EmptyTheQueue(Queue *q)
{
    Item dummy;
    while (!QueueIsEmpty(q))
        DeleteQueue(q, &dummy);
}
