#include<iostream>
using namespace std;
// use of reference type veriable
//int x = a  =>100
//int &x = a
void mySwap(int &x,int &y)
{
    int t = x;
    x = y;
    y = t;
}

int main()
{
    int a=100,b=999;
    cout<<"\n before swap a = "<<a<<"  b = "<<b;
    //mySwap(100,999)
    mySwap(a,b);
    cout<<"\n after swap a = "<<a<<"  b = "<<b;
    return 0;
}