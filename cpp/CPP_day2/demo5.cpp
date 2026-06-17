#include<stdio.h>

class time
{
    private:
        int hr;  //4
        int min; //4
        int sec; //4
    public:
        void printTime()
        {
            printf("\n Time = %d : %d : %d",this->hr,this->min,this->sec);
        }
        void acceptTime()
        {
            printf("\n Enter time");
            scanf("%d%d%d",&this->hr,&this->min,&this->sec);
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
};//end of class

int main()
{
    time t1; //if time is class t1 => object of class time
    printf("\n size of t1 object = %d",sizeof(t1)); //=12 bytes
    t1.acceptTime();
    // t1.hr=3;
    t1.printTime();
    

    time t2;
    t2.acceptTime();
    t2.printTime();


    time t3;
    t3.acceptTime();
    t3.printTime();
    return 0;
}