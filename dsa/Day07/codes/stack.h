#ifndef __STACK_H
#define __STACK_H

#define SIZE 30

typedef struct stack
{
    struct node * arr[SIZE]; // int arr[SIZE]
    int top;
}stack;

struct node* Peek(stack *ps); // int peek(stack *ps)
void init_stack(stack *ps);
void push(stack *ps,struct node* data); // void push(stack *ps, int data)
void pop(stack *ps);
int stack_full(stack *ps);
int stack_empty(stack *ps);

#endif