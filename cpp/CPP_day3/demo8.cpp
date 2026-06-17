#include<iostream>
using namespace std;
// copy constructor demo

class complex
{
    int real;
    int imag;
    public:
    complex(int r=1,int i=1)
    {
        this->real=r;
        this->imag=i;
    }
    //complex &obj=c1
    complex(complex &obj)
    {
        cout<<"\n ---------complex(complex &obj)--------";
        //this => cc
        this->real=obj.real;
        this->imag=obj.imag;
    }
    void printComplexNumber()
    {
        cout<<" Complex Number="<<this->real<<"+j"<<this->imag;
    }
};

int main()
{
    complex c1(5,7);
    cout<<"\n c1 => ";
    c1.printComplexNumber();
    
    complex cc(c1);  //complex cc=c1; 
    cout<<"\n cc => ";
    cc.printComplexNumber();

    return 0;
}