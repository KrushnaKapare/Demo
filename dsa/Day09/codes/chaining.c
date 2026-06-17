#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10
#define H(k) k%SIZE

typedef struct student
{
    int roll_no;
    char name[20];
    float marks;
}student;

struct node
{
    student entry;
    struct node *next;
};

struct list
{
    struct node *head;
};


// Hashtable of linked list (an array of linked list)
struct list hash_table[SIZE];
void init_list();
struct node* create_node();
void add_student(int roll_no, char name[20],float marks);
void display();

int main()
{
    init_list();
    add_student(4002,"A",99); // 2
    add_student(3020,"B",90); // 0
    add_student(6048,"C",70); // 8
    add_student(2120,"D",65); // 0 next of 3020 ->
    add_student(3672,"E",55); // 2 next of 4002 ->
    add_student(5105,"F",88); // 5
    add_student(7229,"G",72); // 9
    add_student(9999,"H",89); // 9 next of 7229 ->
    display();
    return 0;
}

void init_list()
{
    for(int i = 0; i<SIZE; i++)
    {
        hash_table[i].head = NULL;
    }
}

struct node* create_node()
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->entry.roll_no = 0;
    strcpy(new_node->entry.name,"");
    new_node->entry.marks = 0.0;
    new_node->next = NULL;

    return new_node;
}

//  add_student(8,"A",90)
void add_student(int roll_no, char name[20],float marks)
{
    // create a node
     struct node *new_node = create_node();
     // update the data part(entry)
     new_node->entry.roll_no = roll_no;
     strcpy(new_node->entry.name,name);
     new_node->entry.marks = marks;
     // attach it to the hashtable(array) of linked list
     int slot = H(roll_no);
     // slot = 8
     if(hash_table[slot].head == NULL)
     {
        hash_table[slot].head = new_node;
        return;
     }
     struct node *trav = hash_table[slot].head;

     while(trav->next != NULL)
     {
        trav = trav->next;
     }
     trav->next = new_node;

}

void display()
{
    for(int i =0; i<SIZE; i++)
    {
        printf("[%d] :",i);

        if(hash_table[i].head != NULL)
        {
            struct node *trav = hash_table[i].head;
            printf("Head");
            while(trav != NULL)
            {
                printf("->%d,%s,%.f ",trav->entry.roll_no,trav->entry.name,trav->entry.marks);
                trav = trav->next;
            }
           
        }
         printf("\n");
    }

}