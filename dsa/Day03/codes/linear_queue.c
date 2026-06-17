#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct queue
{
    int arr[SIZE];
    int rear;
    int front;
};
void init_queue(struct queue *pq);
void enqueue(int data,struct queue *pq);
void dequeue(struct queue *pq);
int peek(struct queue *pq);
int queue_full(struct queue *pq);
int queue_empty(struct queue *pq);

int main()
{
    struct queue Q; // Q is the variable of struct queue datatype 
    init_queue(&Q); // 100
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

void init_queue(struct queue *pq)
{
    pq->rear = -1;
    pq->front = -1;
}

void enqueue(int data,struct queue *pq)
{
    // 1. increment the rear
    pq->rear++;

    // 2. insert the data at the rear index.
    pq->arr[pq->rear] = data;

    // if front is at -1 , bring front to 0
    if(pq->front == -1)
        pq->front = 0;
}


void dequeue(struct queue *pq)
{
    // optional : make the value of arr[front] as 0
    pq->arr[pq->front] = 0;

    // increment the front
    pq->front++;
}

int peek(struct queue *pq)
{
    return pq->arr[pq->front];
}

int queue_full(struct queue *pq)
{
    if(pq->rear == SIZE-1)
        return 1;
    else
        return 0;
}

int queue_empty(struct queue *pq)
{
    if(pq->rear == -1 || pq->front > pq->rear)
        return 1;
    else
        return 0;
}