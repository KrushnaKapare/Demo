#include<iostream>
using namespace std;

void staticDemo()
{
    int simple=1;
    static int staticData;
	staticData++;
    cout<<"\n staticData = "<<staticData;
}


int main()
{
	staticDemo();
	staticDemo();
	staticDemo();	
    return 0;
}