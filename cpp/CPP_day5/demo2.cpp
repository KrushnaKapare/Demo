#include<iostream>
using namespace std;

//Inheritance [is-a]  
//parent class
class base
{
    public:
    int b;
    void funBase()
    {
        cout<<"\n -------funBase()------";
    }
};
//child
class derived :public base
{
    public:
    int d;  //2 DM 
    void funDerived() //2MF
    {
        cout<<"\n -------funDerived()------";
    }
};
int main()
{
    // base b1;
    // b1.funBase();
    // cout<<"\n size of b1 = "<<sizeof(b1); //4


    derived d1;
    d1.funDerived();
    d1.funBase();
    cout<<"\n size of d1 = "<<sizeof(d1); //4
    return 0;
}