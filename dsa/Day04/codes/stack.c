#include "stack.h"

void init_stack(stack *ps)
{
    ps->top = -1;
}

void push(int data, stack *ps)
{
    // increment the top
    ps->top++;

    // insert the data at the top index
    ps->arr[ps->top] = data;
}

void pop(stack *ps)
{
    // optional :
    ps->arr[ps->top] = 0;
    ps->top--; 
}

int peek(stack *ps)
{
    return ps->arr[ps->top];
}

int stack_full(stack *ps)
{
    return ps->top == SIZE-1;
}

int stack_empty(stack *ps)
{
    return ps->top == -1;
}