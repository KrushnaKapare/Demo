// Linear Queue

#include"queue.h"



void init_queue(queue *pq)
{
    pq->rear = -1;
    pq->front = -1;
}

void enqueue(queue *pq, struct node* data)
{
    // increment the rear
    pq->rear++;

    // insert the data at the rear position
    pq->arr[pq->rear] = data;

    // if front variable is at -1, bring it to 0
    if(pq->front == -1)
        pq->front = 0;

}

void dequeue(queue *pq)
{
    // increment the front
    pq->front++;
}

struct node* peek(queue *pq)
{
    return pq->arr[pq->front];
}

int queue_full(queue *pq)
{
    if(pq->rear == SIZE-1)
        return 1;
    else
        return 0;

    // return (pq->rear == SIZE-1);
}

int queue_empty(queue *pq)
{
    if(pq->rear == -1 || pq->front > pq->rear)
        return 1;
    else
        return 0;
}