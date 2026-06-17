#ifndef __Queue_H
#define __Queue_H

#define SIZE 30


typedef struct Queue
{
    struct node *arr[SIZE]; // int arr[SIZE]
    int rear;
    int front;
}queue;


void init_queue(queue *pq);
void enqueue(queue *pq, struct node* data); // enqueue(queue *pq, int data);
void dequeue(queue *pq);
struct node* peek(queue *pq); // int peek(queue* pq)
int queue_full(queue *pq);
int queue_empty(queue *pq);

#endif