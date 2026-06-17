#include<stdio.h>
#include "stack.h"

int is_operand(char ch);
int priority(char op);
void in_to_post(char infix[],char postfix[]);

int main()
{
    char infix[] = "5+9-4*(8-6/2)+1$(7-3)";
    char postfix[30];
    printf("Infix = %s\n",infix);
    in_to_post(infix,postfix);
    printf("Postfix = %s\n",postfix);
    return 0;
}
void in_to_post(char infix[],char postfix[])
{
    stack S;
    init_stack(&S);
    int j = 0;
    for(int i = 0; infix[i] != '\0'; i++)
    {
        // if current element is an operand
       
        if(is_operand(infix[i])) // if(1)
        {
             // append it to postfix exp
             postfix[j] = infix[i];
             j++;
        }
        else if (infix[i] == '(')
        {
            // push it on the stack
            push('(',&S);
        }
        else if(infix[i] == ')')
        {
            char ch;
            while((ch = peek(&S)) != '(')
            {
                // append it to postfix
                postfix[j++] = ch;
                pop(&S);
            }
            pop(&S); // pop/ discard opeining bracket.
        }
        else // it is an operator
        {
            while(!stack_empty(&S) && priority(peek(&S)) >= priority(infix[i]))
            {
                // append the topmost element in the postfix exp
                postfix[j++] = peek(&S);
                pop(&S);
            }
            push(infix[i],&S);
        }
    }
    // append the remaining elements from the stack
    while(!stack_empty(&S))
    {
        postfix[j++] = peek(&S);
        pop(&S);
    }
    postfix[j] = '\0';
}

int is_operand(char ch) // '5'
{
    return ch >= 48 && ch <= 57;
}

int priority(char op)
{
    switch(op)
    {
        case '$' : return 10;
        case '*' :
        case '/' :
        case '%' : 
                    return 9;
        case '+' :
        case '-' :
                    return 8;
        case '(' :
        default :   
                    return 0;
        
    }
}