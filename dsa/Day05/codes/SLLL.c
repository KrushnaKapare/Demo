#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node* create_node();
void add_first(int data);
void display();
void add_last(int data);
void add_at_pos(int data,int pos);
int count_nodes();
void delete_first();
void delete_at_pos(int pos);
void delete_last();

int main()
{
    add_first(10);
    add_first(20);
    add_first(15);
    add_first(25);
    printf("\n Add First :\n");
    display();
    // head->25->15->20->10
    add_last(50);
    add_last(80);
    add_last(75);
    printf("\n Add Last :\n");
    display();
    // head->25->15->20->10->50->80->75
    add_at_pos(90,5);
    printf("\n Add at pos :\n");
    display();
    // head->25->15->20->10->90->50->80->75
    delete_first();
    printf("\n Delete First Node :\n");
    display();
    // head->15->20->10->90->50->80->75
    delete_last();
    printf("\n Delete Last :\n");
    display();
    // head->15->20->10->90->50->80
    delete_at_pos(4);
    printf("\n Delete at pos :\n");
    display();
    // head->15->20->10->50->80

    return 0;
}

struct node* create_node()
{
    struct node *ptr= (struct node*)malloc(sizeof(struct node));
    ptr->data = 0;
    ptr->next = NULL;
    return ptr; // return 500
}

void add_first(int data) // 20
{
    // 1. create a node
   struct node* ptr = create_node();
   // 2. update the default value of the node data
   ptr->data = data;

   // 3. attach the node to the linked list
   // a. if the list is empty
   if(head == NULL)
    head = ptr;
   else
   {
    // b. if the list has multiple nodes
    // 1. create a link between the new node and the 1st node.
    ptr->next = head;
    // 2. update the head pointer to point to the new node
    head = ptr;
   }

}

void display()
{
    if(head == NULL)
        printf("Linked List is Empty !\n");
    else
    {
        struct node *trav = head;
        printf("Head");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
    }
}

void add_last(int data)
{
    struct node *ptr = create_node();
    ptr->data = data;

    if(head == NULL)
    {
        head = ptr;
    }
    else
    {
        struct node *trav = head;

        while(trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = ptr;
    }
}

void add_at_pos(int data,int pos)
{
    if(head == NULL)
    {
        if(pos == 1)
            add_first(data);
        else
            printf("Invalid pos number !\n");
    }
    else if(pos == 1)
        add_first(data);
    else if(pos == count_nodes()+1)
        add_last(data);
    else if(pos < 1 || pos > count_nodes()+1)
        printf("Invalid pos number !\n");
    else
    {
        struct node *ptr = create_node();
        ptr->data = data;
        // traverse till pos-1
        struct node *trav = head;
        for(int i =1; i< pos-1; i++)
            trav = trav->next;
        ptr->next = trav->next;
        trav->next = ptr;
    }

}

int count_nodes()
{
    int count = 0;
    if(head == NULL)
        printf("List is empty !\n");
    else
    {
        
        struct node *trav = head;
        while(trav != NULL)
        {
            count++;
            trav = trav->next;
        }
    }
    return count;
}

void delete_first()
{
    if(head== NULL)
        printf("List is Empty !\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        // take a backup of 1st node in temp
        struct node *temp = head;
        // update the head pointer
        head = head->next;
        // OR head = temp->next

        // free the temp node
        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head==NULL)
    {
        printf("List is Empty !\n");
    }
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        // traverse till second last node
        struct node *trav = head;
        while(trav->next->next != NULL)
        {
            trav = trav->next;
        }
        // free the last node.
        free(trav->next);
        trav->next = NULL;
    }
}

void delete_at_pos(int pos)
{
    if(head == NULL)
        printf("List is empty !\n");
    else if(pos == 1)
        delete_first();
    else if(pos == count_nodes())
        delete_last();
    else if(pos < 1 || pos > count_nodes())
        printf("Invalid number !\n");
    else
    {
        // traverse till pos-1
        struct node *trav = head;

        for(int i =1; i<pos-1;i++)
            trav = trav->next;

        // take a backup of pos node
        struct node *temp = trav->next;

        // link the pos-1 node and pos+1 node
        trav->next = temp->next;

        // free temp
        free(temp);
        temp = NULL;
    }
}