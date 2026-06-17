#include<iostream>
using namespace std;
class complex
{
    int real; //4
    int imag; //4
    static int count; 
    public:
    complex(int r=1,int i=1)
    {
        cout<<"\n -----complex()-------";
        this->real=r;
        this->imag=i;
        count++;
    }
    void printCount()
    {
        cout<<"\n value of count = "<<this->count<<" address of count = "<<&count;
    }
    void printComplexNumber()
    {
        cout<<"\n Complex Number="<<this->real<<"+j"<<this->imag;
    }  
};

int complex::count = 0;  //global definition of static data member


int main()
{
    complex c1(1,2);
    cout<<"\n size of c1 = "<<sizeof(c1);
    c1.printCount();

    complex c2;
    c2.printCount();
    return 0;
}