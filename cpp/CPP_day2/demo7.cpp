#include<stdio.h>

class time
{
    private:
        int hr;  //4
        int min; //4
        int sec; //4
    public:
        time()//Constructor
        {
            printf("\n ---------- time()--------");
            this->hr=0;
            this->min=0;
            this->sec=0;
        }
        time(int h,int m,int s)//Constructor
        {
            printf("\n ---------- time(int,int,int)--------");
            this->hr=h;
            this->min=m;
            this->sec=s;
        }
       
        void initTime()
        {
            this->hr=0;
            this->min=0;
            this->sec=0;
        }
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
        ~time()//Destructor
        {
             printf("\n ---------- ~time()--------");
        }
};//end of class

int main()
{
   time t1;
   t1.printTime();

   time t2;
   t2.printTime();

   time t_p(7,30,23);
   t_p.printTime();

   time t_s(9,45,12);
   t_s.printTime();
    return 0;
}