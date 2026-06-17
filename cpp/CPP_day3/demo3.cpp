#include<iostream>
using namespace std;
// class complex = using cin and cout
class complex
{
    int real;   //4
    int imag;   //4
    public:
    // complex()
    // {
    //     cout<<"\n --------complex()---------";
    //     this->real = 1;
    //     this->imag = 1;
    // }
    complex(int r=1,int i=1)
    {
        cout<<"\n --------complex(int,int)---------";
        this->real = r;
        this->imag = i;
    }
    void printComplexNumber()
    {
        //5+j7
        cout<<"\n Complex Number = "<<this->real<<"+j"<<this->imag;
    }
    void acceptComplexNumber()
    {
        cout<<"\n Enter Complex Number";
        cin>>this->real>>this->imag;
    }
    ~complex()
    {
        cout<<"\n -------- ~complex()---------";
    }

};

int main()
{
    complex c1;
    c1.printComplexNumber();
    c1.acceptComplexNumber();
    c1.printComplexNumber();

    complex c2(5,7);
    c2.printComplexNumber();
    return 0;
}