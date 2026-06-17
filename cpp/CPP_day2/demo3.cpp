#include<stdio.h>

struct time
{
    int hr;
    int min;
    int sec;

    void printTime()
    {
        printf("\n Time = %d : %d : %d",hr,min,sec);
    }
    void acceptTime()
    {
        printf("\n Enter time");
        scanf("%d%d%d",&hr,&min,&sec);
    }
    void incrTimeByOneSec()
    {
        sec++;
        if(sec >= 60)
        {
            sec = 0;
            min++;
        }
        if(min >= 60)
        {
            min = 0;
            hr++;
        }
        if(hr >= 24)
            hr = 0;
    }
};//end of struct

int main()
{
    int num1;
    struct time t1;
    t1.hr=8;
    t1.min=30;
    t1.sec=55;
    t1.printTime();
    t1.acceptTime();
    t1.printTime();
    t1.incrTimeByOneSec();
    t1.printTime();
    return 0;
}