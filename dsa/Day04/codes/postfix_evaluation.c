#include<stdio.h>
#include<math.h>
#include "stack.h"

int postfix_evaluation(char postfix[]);
int is_operand(char ch);
int calculate(int op1,int op2, char op);

int main()
{
    char postfix[] = "59+4862/-*-173-$+";
    int result = postfix_evaluation(postfix);
    printf("result = %d\n",result);
    return 0;
}

int postfix_evaluation(char postfix[])
{
    stack S;
    init_stack(&S);
    for(int i = 0; postfix[i] != '\0'; i++)
    {
        if(is_operand(postfix[i]))
        {
            // push it on the stack
            push(postfix[i]-'0',&S);
        }
        else // it is an operator
        {
            // pop 2 operands from the stack
            int op2 = peek(&S); pop(&S);
            int op1 = peek(&S); pop(&S);
            int res = calculate(op1,op2,postfix[i]);
            // push the temp res on the stack
            push(res,&S);
        }
    }
    int final_res = peek(&S);
    pop(&S);
    return final_res;
}

int is_operand(char ch)
{
    return ch >= 48 && ch <=57;
}

int calculate(int op1,int op2, char op)
{
    switch(op)
    {
        case '*' : return op1 * op2;
        case '/' : return op1 / op2;
        case '%' : return op1 % op2;
        case '+' : return op1 + op2;
        case '-' : return op1 - op2;
        case '$' : return pow(op1,op2);
    }
}