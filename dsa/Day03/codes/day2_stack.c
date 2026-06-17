#include<stdio.h>
#include<stdlib.h>
#define SIZE 5


typedef struct stack
{
    int arr[SIZE];
    int top;
}stack;

void init_stack(stack *ps);
void push(int data, stack *ps);
int peek(stack *ps);
int stack_empty(stack *ps);
void pop(stack *ps);
int stack_full(stack *ps);

int main()
{
    stack S;
    init_stack(&S);
    int choice;
do{
    printf("0.Exit\n1.Push\n2.Pop\n3.Peek :\n");
    printf("Enter your choice :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0 :
                exit(0);
        case 1 : // push
                    if(stack_full(&S))
                    {
                        printf("Stack is Full !\n");
                    }
                    else
                    {
                        int data;
                        printf("enter the data to push :");
                        scanf("%d",&data);
                        push(data,&S);
                        printf("Data pushed = %d\n",data);
                    }
                    break;
            case 2 : // pop
                    if(stack_empty(&S))
                    {
                        printf("Stack is empty !\n");
                    }
                    else
                    {
                        int val = peek(&S);
                        pop(&S);
                        printf("Value popped = %d\n",val);
                    }
                    break;
        case 3: // Peek
                if(stack_empty(&S))
                {
                    printf("Stack empty ! peek not possible !\n");
                }
                else
                {
                    int val = peek(&S);
                    printf("Topmost value = %d\n",val);
                }
                break;
        default:
                printf("Invalid Choice !");
    }
}while(choice != 0);
    return 0;
}

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