#include<iostream>
using namespace std;
//add accept() function


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
    void printPerson() //2
    {
        cout<<"\n name = "<<name <<" age = "<<age;
    }
    virtual void accept() //2
    {
        cout<<"\n Enter name and age";
        cin>>name>>age;
    }
    bool canVote()
    {
        if(age >= 18)
            return true;
        else
            return false;
    }
};
//emp is-a person
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
    void accept() //4
    {
        cout<<"\n Enter name and age";
        cin>>name>>age;
        cout<<"\n Enter sal and empid";
        cin>>sal>>empid;
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
    // pptr->accept();
    // pptr->printPerson();
    // pptr->canVote();


    // emp e1;
    // emp *eptr = NULL;
    // eptr = &e1;
    // eptr->accept();
    // eptr->printEmp();
    

    emp e1; //dm = 4 
    person *pptr = NULL;
    pptr = &e1;  //base class(person) pointer can hold the object of derived class(emp)
    pptr->accept();
    pptr->printPerson();//2
    pptr->canVote(); 
    //pptr->printEmp();  //error


    // person p2;
    // emp e2;
    // p2=e2;  //object slicing.



    return 0;
}