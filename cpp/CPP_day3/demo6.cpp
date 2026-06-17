#include<iostream>
using namespace std;
// reference => basic concept demo

int main()
{
    int n1;
    n1=15;

    int &ref = n1;
    ref = 50;

    cout<<"\n value of n1 = "<<n1<<" address of n1 = "<<&n1;
    cout<<"\n value of ref = "<<ref<<" address of ref = "<<&ref;

    return 0;
}