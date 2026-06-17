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
      
        //setter
        //t_p.setMin(15);
        void setMin(int min) //Mutators / setter 
        {
            //data member = para
            this->min = min;
        }
        //setHr()
        //setSec()
        //int my_Sec = t_p.getSec();
        int getSec() //inspector/getter 
        {
            return this->sec;
        }

        void initTime()
        {
            this->hr=0;
            this->min=0;
            this->sec=0;
        }
        void printTime()//Facilitator
        {
            printf("\n Time = %d : %d : %d",this->hr,this->min,this->sec);
        }
        void acceptTime()//Facilitator
        {
            printf("\n Enter time");
            scanf("%d%d%d",&this->hr,&this->min,&this->sec);
        }
        void incrTimeByOneSec()//Facilitator
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
   time t_p(7,30,23);
   t_p.printTime();

   //t_p.min = 15;
   t_p.setMin(15);
   t_p.printTime();

   //int my_Sec=t_p.sec;
   int my_Sec = t_p.getSec();
   printf("\n my sec value = %d",my_Sec);
  
    return 0;
}