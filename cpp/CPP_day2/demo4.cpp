#include<stdio.h>

struct time
{
    private:
        int hr;
        int min;
        int sec;
    public:
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
    time t1; //if time is struct then t1=> vari of time struct
    t1.acceptTime();
    // t1.hr=3;
    t1.printTime();
    
    return 0;
}