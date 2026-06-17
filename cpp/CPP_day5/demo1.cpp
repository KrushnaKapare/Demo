#include<iostream>
using namespace std;

//Association
//car has-a engine

class engine
{
    int cc,fuel;
    public:
    void acceptEngine()
    {
        cout<<"\n Enter engine data as cc and fuel=" ;
        cin>>cc>>fuel;
    }
    void printEngine()
    {
        cout<<"\n Engine info cc = "<<cc<<" fuel = "<<fuel;
    }
};

class car
{
    int price;
    engine e1; //
    public:
    void accpetCar()
    {
        cout<<"\n enter car price ";
        cin>>price;
        e1.acceptEngine();
    }
    void printCar()
    {
        cout<<"\n car price = "<<price;
        e1.printEngine();
    }
};

int main()
{
    // engine e1;
    // e1.acceptEngine();
    // e1.printEngine();

    car c1;
    c1.accpetCar();
    c1.printCar();
   
    return 0;
}

