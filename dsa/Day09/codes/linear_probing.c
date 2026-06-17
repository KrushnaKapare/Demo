#include<stdio.h>
#include<string.h>
#define SIZE 10
#define H(k) k%SIZE
#define N_H(k) (k+1) % SIZE

typedef struct student
{
    int roll_no;
    char name[20];
    float marks;
}student;

// int arr[SIZE]
student hashtable[SIZE];
void add_student(int roll_no, char name[20],float marks);
int search(int key);

void display();

int main()
{
    add_student(4002,"A",99); // 2
    add_student(3020,"B",90); // 0
    add_student(6048,"C",70); // 8
    add_student(2120,"D",65); // 1
    add_student(3672,"E",55); // 3
    add_student(5105,"F",88); // 5
    add_student(7229,"G",72); // 9
    add_student(9999,"H",89); // 4

    display();
    int slot = search(3677);
    if(slot != -1)
    {
        printf("Details Found = %d-%s-%.f\n",hashtable[slot].roll_no,hashtable[slot].name,hashtable[slot].marks);
    }
    else
        printf("Student Not found !\n");

    return 0;
}

// add_student(9002,A,90)
void add_student(int roll_no, char name[20],float marks)
{
    student s1;
    s1.roll_no = roll_no;
    strcpy(s1.name,name);
    s1.marks = marks;

    // find the slot
    int slot = H(roll_no);

    if(hashtable[slot].roll_no == 0)
    {
        hashtable[slot] = s1;
        return;
    }

    int new_slot = slot; // 2

    for(int i = 0; i < SIZE; i++)
    {
        new_slot = N_H(new_slot);
        if(hashtable[new_slot].roll_no == 0)
        {
            hashtable[new_slot] = s1;
            return;
        }
    }
}

void display()
{
    for(int i=0; i< SIZE; i++)
    {
        printf("[%d] : %d-%s-%.2f\n",i,hashtable[i].roll_no,hashtable[i].name,hashtable[i].marks);
    }
}

int search(int key) // 9002
{
    int slot = H(key);

    if(hashtable[slot].roll_no == key)
    {
        return slot;
    }
    int new_slot = slot;

    for(int i =0; i<SIZE; i++)
    {
        new_slot = N_H(new_slot);
        if(hashtable[new_slot].roll_no == key)
        {
            return new_slot;
        }
    }
    return -1; // key not found
}