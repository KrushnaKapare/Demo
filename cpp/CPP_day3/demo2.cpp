// cin cout demo
#include<iostream>
using namespace std;



#include<stdio.h>
//printf() => cout  using  <<  (insertion operator)
//scanf() =>  cin   using  >>  (Extraction operator)

int main()
{
    printf("\n Good morning .. :( ");
    cout<<"\n Good morning .. :( ";

    int n1 = 33;
    printf("\n value of n1 = %d",n1);
    cout<<"\n value of n1 = "<<n1;

    int sal=25000,eid=204;
    printf("\n sal = %d eid = %d",eid,sal);
    cout<<"\n sal = "<<sal<<" eid = "<<eid;
    
    int age;
    cout<<"\n enter age";
    //scanf("%d",&age);
    cin>>age;
    cout<<"\n  age = "<<age;

    //int sal=25000,eid=204;
    cout<<"\n Enter sal and eid";
    //scanf("%d%d",&sal,&eid);
    cin>>sal>>eid;
    cout<<"\n sal = "<<sal<<" eid = "<<eid;

    return 0;
}

