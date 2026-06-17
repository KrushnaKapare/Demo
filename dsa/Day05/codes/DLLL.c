#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;

node *head = NULL;
node *tail = NULL;

node * create_node();
void add_first(int data);
void forward_display();
void backward_display();
void add_last(int data);
void add_at_pos(int data,int pos);
int count_nodes();
void delete_first();
void delete_last();
void delete_at_pos(int pos);

int main()
{
    add_first(10);
    add_first(20);
    add_first(30);
    printf("Add First :");
    printf("\n Forward Display :");
    forward_display();
    // Head->30->20->10
    printf("\n Backward Display :");
    backward_display();
    // Tail->10->20->30

    add_last(70);
    add_last(50);
    add_last(90);
    printf("\n\n Add Last :");
    printf("\n Forward Display :");
    forward_display();
    // Head->30->20->10->70->50->90
    printf("\n Backward Display :");
    backward_display();
    // Tail->90->50->70->10->20->30

    add_at_pos(100,5);
    printf("\n\n Add at pos :");
    printf("\n Forward Display :");
    forward_display();
    // Head->30->20->10->70->100->50->90
    printf("\n Backward Display :");
    backward_display();
    // Tail->90->50->100->70->10->20->30

    delete_first();
    printf("\n\n Delete First :");
    printf("\n Forward Display :");
    forward_display();
    // Head->20->10->70->100->50->90
    printf("\n Backward Display :");
    backward_display();
    // Tail->90->50->100->70->10->20

    delete_last();
     printf("\n\n Delete Last :");
    printf("\n Forward Display :");
    forward_display();
    // Head->20->10->70->100->50
    printf("\n Backward Display :");
    backward_display();
    // Tail->50->100->70->10->20

    delete_at_pos(3);
     printf("\n\n Delete at pos :");
    printf("\n Forward Display :");
    forward_display();
    // Head->20->10->100->50
    printf("\n Backward Display :");
    backward_display();
    // Tail->50->100->10->20

    return 0;
}


node * create_node()
{
    node* ptr = (node*)malloc (sizeof(node));
    ptr->prev = NULL;
    ptr->data = 0;
    ptr->next = NULL;

    return ptr;
}

void add_first(int data)
{
    node* new_node = create_node();
    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void forward_display()
{
    if(head == NULL)
        printf("List is empty !\n");
    else
    {
        node *trav = head;
        printf("Head");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
    }
}

void backward_display()
{
    if(head == NULL)
        printf("List is empty !\n");
    else
    {
        struct node *trav = tail;
        printf("Tail");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->prev;
        }
    }
}

void add_last(int data)
{
    node* new_node = create_node();
    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}

void add_at_pos(int data,int pos)
{
    node *new_node = create_node();
    new_node->data = data;

    if(head == NULL)
    {
        if(pos == 1)
            add_first(data);
        else
            printf("Invalid !\n");
    }
    else if(pos == 1)
        add_first(data);
    else if(pos == count_nodes()+1)
        add_last(data);
    else if(pos < 1 || pos > count_nodes())
        printf("Invalid !\n");
    else
    {
        struct node *trav = head;
        for(int i =1; i<pos-1; i++)
            trav = trav->next;

        new_node->prev = trav;
        new_node->next = trav->next;
        trav->next->prev = new_node;
        trav->next = new_node;
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
    if(head == NULL)
        printf("List is Empty !\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head == NULL)
        printf("List is empty !\n");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        struct node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
        temp = NULL;
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
    else if(pos <1 || pos > count_nodes())
        printf("Invalid ");
    else
    {
        struct node *trav = head;
        for(int i = 1; i<pos-1; i++)
            trav = trav->next;
        
        struct node *temp = trav->next;

        trav->next = temp->next;

        temp->next->prev = trav;
        free(temp);
        temp = NULL;
    }
}