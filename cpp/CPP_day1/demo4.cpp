#include<stdio.h>
//Function Overloading


void printValue(int a)
{
    printf("\n value of int a=%d",a);
}
//Return type is not considered for function overloading
// int printValue(int a) //error
// {
//     printf("\n value of int a=%d",a);
//     return a;
// }
void printValue(int a,int b)
{
    printf("\n value of int a=%d, int b=%d",a,b);
}
void printValue(char a)
{
    printf("\n value of char a=%c",a);
}
void printValue(int a,char c)
{
    printf("\n value of int a=%d  char c=%c",a,c);
}
void printValue(char c,int a)
{
    printf("\n value of   char c=%c int a=%d",c,a);
}
int main()
{
    printValue(10);
    printValue(11,22);
    printValue('A');
    printValue(44,'W');
    printValue('S',6);
    return 0;
}