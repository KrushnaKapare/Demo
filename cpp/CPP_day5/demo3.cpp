#include<iostream>
using namespace std;
//protected data member



//base class
//parent class
class person
{
    protected:
        string name;
        int age;
    public:
    person()
    {
        name = "Ravi";
        age = 24;
    }
    void printPerson()
    {
        cout<<"\n name = "<<name <<" age = "<<age;
    }
    bool canVote()
    {
        if(age >= 18)
            return true;
        else
            return false;
    }
};

//derived class
//child class
class emp : public person
{
    int sal;
    int empid;
    public:
    emp()
    {
        sal = 25000;
        empid = 304;
    }
    void printEmp()  //4
    {
        this->printPerson(); //2
        cout<<" sal = "<< sal <<"  empid = "<<empid;
    }
    void updateName(string newName)
    {
        name = newName;  //valid
    }
};
int main()
{
    // person p1;
    // p1.printPerson();
    // if(p1.canVote())
    //     cout<<"\n yes can do vote  :)";
    // else
    //     cout<<"\n No can't do vote  :(";



    emp e1;
    e1.printEmp();

    //ravi => ravee
    e1.name = "ravan"; //invalid
    e1.updateName("ravee");
    return 0;
}