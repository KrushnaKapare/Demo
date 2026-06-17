#include<iostream>
using namespace std;
// const => basic concept demo

int main()
{
    int n1;
    n1=50;
    n1=100;

    int n2=89;

    const int c=20; 

    // c++;  //error
    // c=90; //error

    cout<<"\n const c = "<<c;
    return 0;
}