#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct queue
{
    int arr[SIZE];
    int rear;
    int front;
}queue;

void init_queue(queue *pq);
void enqueue(int data,queue *pq);
void dequeue(queue *pq);
int queue_empty(queue *pq);
int queue_full(queue *pq);
int peek(queue *pq);

int main()
{
    queue Q;
    init_queue(&Q);

            int choice;
do{

    printf("0.Exit\n1.Enqueue\n2.Dequeue\n3.Peek:\n");
    printf("Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0 :
                exit(0);
        case 1: // enqueue 
                if(queue_full(&Q)) // if(0)
                {
                    printf("Queue is Full !\n");
                }
                else
                {
                    int data;
                    printf("Enter the data to insert in the Q :");
                    scanf("%d",&data);
                    enqueue(data,&Q);
                    printf("Data entered = %d\n",data);
                }
                break;
        case 2: // dequeue 
                if(queue_empty(&Q)) // if(0)
                {
                    printf("Q is empty !\n");
                }
                else
                {
                    int val = peek(&Q); // 10
                    dequeue(&Q);
                    printf("Value deleted = %d\n",val);
                }
                break;
    case 3 : // peek
            if(queue_empty(&Q))
                printf("Q is empty ! Peek not Possible !\n");
            else
            {
                int val = peek(&Q);
                printf("FrontMost element = %d\n",val);
            }
            break;
    default :
            printf("Invalid choice. ");
    }
}while(choice != 0);
    return 0;
}

void init_queue(queue *pq)
{
    pq->rear = -1;
    pq->front = -1;
}

void enqueue(int data,queue *pq)
{
    // 1. increment the rear
    pq->rear = (pq->rear+1) % SIZE; // instead of pq->rear++

    pq->arr[pq->rear] = data;

    if(pq->front == -1)
        pq->front = 0;
}

void dequeue(queue *pq)
{
    if(pq->front == pq->rear) // deleting the last element
    {
        pq->arr[pq->front] = 0;
        pq->rear = -1; // reset the front and rear to start the queue again
        pq->front = -1;
    }
    else
    {
        pq->arr[pq->front] = 0;
        pq->front = (pq->front+1) % SIZE; // instead of front++
    }
}

int peek(queue *pq)
{
    return pq->arr[pq->front];
}

int queue_empty(queue *pq)
{
    if(pq->rear == -1)
        return 1;
    else
        return 0;
}

int queue_full(queue *pq)
{
    if(pq->front == (pq->rear+1) % SIZE)
        return 1;
    else
        return 0;
}