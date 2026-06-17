#include<iostream>
using namespace std;

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
        cout<<"  sal = "<< sal <<"  empid = "<<empid;
    }
    void updateName(string newName)
    {
        name = newName;  //valid
    }
};
int main()
{
    // int n1 = 89;
    // char *p = NULL;
    // p = &n1;  //error
    // int *ptr = &n1;

    // person p1;
    // person *pptr = NULL;
    // pptr = &p1;
    // pptr->printPerson();
    // pptr->canVote();


    // emp e1;
    // emp *eptr = NULL;
    // eptr = &e1;
    // eptr->canVote();
    // eptr->printPerson();
    // eptr->printEmp();
    // eptr->updateName("Ravee");

    emp e1;
    person *pptr = NULL;
    pptr = &e1;  //base class(person) pointer can hold the object of derived class(emp)
    pptr->printPerson();//2
    pptr->canVote(); 
    //pptr->printEmp();  //error

    return 0;
}
