#include<iostream>
using namespace std;
//Diamond Problem
class A   //1
{
    public:
    void funA()
    {
        cout<<"\n---a::funA()----";
    }
};
class B: virtual public A   //2
{
    public:
    void funB()
    {
        cout<<"\n----B::funB()----";
    }
};

class C: virtual public A   //2
{
    public:
    void funC()
    {
        cout<<"\n ---C::funC()----";
    }
};

class D:public B,public C  //?   3,4,5 ??
{
    public: 
    void funD()
    {
        cout<<"\n------D::funD()-----";
    }
};

int main()
{
    B b1;
    b1.funB();
    b1.funA();




    C c1;  
    c1.funC();
    c1.funA();






    D d1;
    d1.funD();
    d1.funB();
    d1.funC();
    //d1.funF();
    d1.funA();
    







    cout<<"\n";
    return 0;
}