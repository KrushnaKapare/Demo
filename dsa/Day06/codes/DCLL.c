#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;

node* head = NULL;

node* create_node();
void backward_display();
void add_first(int data);
void forward_display();
void add_last(int data);
void delete_first();
void delete_last();

int main()
{
    add_first(50);
    add_first(65);
    add_first(40);
    forward_display();
    backward_display();
    add_last(75);
    add_last(95);
    forward_display();
    backward_display();
    delete_first();
    forward_display();

    delete_last();
    forward_display();
    return 0;
}

node* create_node()
{
    node* new_node = (node*)malloc(sizeof(node));

    new_node->data = 0;
    new_node->prev = NULL;
    new_node->next = NULL;
    
    return new_node;
}

void add_first(int data)
{
    node* new_node = create_node();
    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        new_node->next = head;
        new_node->prev = head;
    }
    else
    {
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
        head = new_node;
    }

}

void forward_display()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else
    {
        node *trav = head;
        printf("Head");
        do
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }while(trav != head);
    }
    printf("\n");
}


void backward_display()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else
    {
        node* trav = head->prev;
    printf("Tail");
        do
        {
            printf("->%d",trav->data);
            trav = trav->prev;
        }while(trav != head->prev);
    }
    printf("\n");
}


void add_last(int data)
{
    node* new_node = create_node();
    new_node->data = data;

    if(head == NULL)
    {
        head = new_node;
        new_node->next = head;
        new_node->prev = head;
    }
    else
    {
        new_node->prev = head->prev;
        new_node->next = head;
        head->prev->next = new_node;
        head->prev = new_node;
    }
}

void delete_first()
{
    if(head == NULL)
        printf("List is empty !\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node* temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;

        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head == NULL)
        printf("List is Empty !\n");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        head->prev = head->prev->prev;
        free(head->prev->next);
        head->prev->next = head;
    }
}