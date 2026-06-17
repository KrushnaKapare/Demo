#include<stdio.h>

struct time
{
    int hr;
    int min;
    int sec;
};
void printTime(struct time t1)
{
    printf("\n Time = %d : %d : %d",t1.hr,t1.min,t1.sec);
}
void acceptTime(struct time *p)
{
    printf("\n Enter time");
    scanf("%d%d%d",&p->hr,&p->min,&p->sec);
}

int main()
{
    int num1;
    struct time t1;
    t1.hr=8;
    t1.min=30;
    t1.sec=55;
    printTime(t1);//call by value
    acceptTime(&t1);//call by address
    printTime(t1);
    return 0;
}