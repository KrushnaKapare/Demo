#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "queue.h"

struct node
{
    struct node* left;
    int data;
    struct node* right;
    int visited;
};

struct node *root = NULL;

struct node* create_node();
void add_node(int data);
void in_order(struct node *trav);
void pre_order(struct node *trav);
void post_order(struct node *trav);
void NR_PreOrder();
void NR_InOrder();
void NR_PostOrder();
void BFS_Traversal();
struct node* Breadth_first_Search(int key);
void DFS_Traversal();
struct node* Depth_first_search(int key);
struct node* BST_Search(int key);
struct node* search_with_parent(int key,struct node **p_parent);
void delete(int key);

int main()
{
//    50, 25, 66, 88, 20,22,90,50,80,36
    add_node(50);
    add_node(25);
    add_node(66);
    add_node(88);
    add_node(20);
    add_node(22);
    add_node(90);
    add_node(50);
    add_node(80);
    add_node(36);
    printf("\n\n Recursive In-Order Traversal :\n");
    in_order(root);
    printf("\n\n NON-Recursive In-Order :\n");
    NR_InOrder();
    printf("\n\n Recursive Pre-Order Traversal :\n");
    pre_order(root);
    printf("\n\n NON-Recursive PreOrder :\n");
    NR_PreOrder();
    printf("\n\n Recursive Post-Order Traversal :\n");
    post_order(root);
    printf("\n\n Non-Recursive Post-Order :\n");
    NR_PostOrder();
    printf("\n\n Non-Recursive Post-Order :\n");
    NR_PostOrder();
/*
    printf("\n\n BFS Traversal :\n");
    BFS_Traversal();

    printf("\n\n Breadth First Search :\n");
    struct node* result = Breadth_first_Search(75);
    if(result != NULL)
        printf("Key found = %d\n",result->data);
    else
        printf("Key not Found !\n");

    printf("\n\n DFS Traversal :\n");
    DFS_Traversal();

    printf("\n\n Depth First Search :\n");    
    result = Depth_first_search(8);
    if(result != NULL)
        printf("Key found = %d\n",result->data);
    else
        printf("Key not Found !\n");

    printf("\n\n BST Search !\n");
    result = BST_Search(90);
    if(result != NULL)
        printf("Key found = %d\n",result->data);
    else
        printf("Key Not Found !\n");

    printf("\n\n Search With Parent :\n");
    struct node* parent;
    result = search_with_parent(80,&parent);

    if(result != NULL)
    {
        printf("Key found : Parent = %d, child = %d\n",parent->data,result->data);
    }
    else
        printf("Key not Found !\n");
    
    printf("\n\n Delete Node :\n");
    delete(22);
    in_order(root);
    */
    return 0;
}


struct node* create_node()
{
    struct node *ptr =(struct node*) malloc(sizeof(struct node));

    ptr->data = 0;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->visited = 0;

    return ptr;
}


void add_node(int data)
{
    // create a node
    struct node *new_node = create_node();
    new_node->data = data;

    // attach it to the tree

    if(root == NULL)
    {
        root = new_node;
    }
    else
    {
        struct node *trav = root;
        while(1)
        {
            if(new_node->data < trav->data)
            {
                if(trav->left == NULL)
                {
                    trav->left = new_node;
                    break;
                }
                else
                {
                    trav = trav->left;
                }
            }
            else
            {
                if(trav->right == NULL)
                {
                    trav->right = new_node;
                    break;
                }
                else
                    trav = trav->right;
            }
        }
    }
}


void in_order(struct node *trav)
{

    if(trav == NULL)
        return;
    
        // left - parent - right
        in_order(trav->left);
        printf("%4d",trav->data);
        in_order(trav->right);

}

void pre_order(struct node *trav)
{
    // parent - left - right
    if(trav == NULL)
        return;
    
    printf("%4d",trav->data);
    pre_order(trav->left);
    pre_order(trav->right);
}

void post_order(struct node *trav)
{
    if(trav == NULL)
        return;

        post_order(trav->left);
        post_order(trav->right);
        printf("%4d",trav->data);

}

void NR_PreOrder()
{
    stack S;
    init_stack(&S);

    struct node *trav = root;
while(trav != NULL || !stack_empty(&S))
{
    while(trav != NULL)
    {
        printf("%4d",trav->data);
        if(trav->right != NULL)
            push(&S,trav->right);
        trav = trav->left;
    }
if(!stack_empty(&S))
{
    trav = Peek(&S);
    pop(&S);
}
}
}

void NR_InOrder()
{
    stack S;
    init_stack(&S);
    struct node *trav = root;

while(trav != NULL || !stack_empty(&S))
{
    while(trav != NULL)
    {
        push(&S,trav);
        trav = trav->left;
    }

    if(!stack_empty(&S))
    {
        trav = Peek(&S);
        pop(&S);
    }
    printf("%4d",trav->data);
    trav = trav->right;
}
}

void NR_PostOrder()
{
    stack S;
    init_stack(&S);

    struct node *trav = root;

    while(trav != NULL || !stack_empty(&S))
    {

        while(trav != NULL)
        {
            push(&S,trav);
            trav = trav->left;
        }

        if(!stack_empty(&S))
        {
            trav = Peek(&S);
            pop(&S);    
        if(trav->right == NULL || trav->right->visited == 1)
        {
            printf("%4d",trav->data);
            trav->visited = 1;
            trav = NULL;
        }
        else
        {
            push(&S,trav);
            trav = trav->right;
        }
        }
    }
}

void BFS_Traversal()
{
     queue Q;
    init_queue(&Q);

    // push the root the queue
    enqueue(&Q,root);

    while(!queue_empty(&Q))
    {
        struct node *trav = peek(&Q);
        dequeue(&Q);
        printf("%4d",trav->data);
        if(trav->left != NULL)
            enqueue(&Q,trav->left);
        if(trav->right != NULL)
            enqueue(&Q,trav->right);
    }

}

struct node* Breadth_first_Search(int key)
{
    queue Q;
    init_queue(&Q);

    enqueue(&Q,root);

    while(!queue_empty(&Q))
    {
        struct node *trav = peek(&Q);
        dequeue(&Q);
        if(trav->data == key)
            return trav;
        if(trav->left != NULL)
            enqueue(&Q,trav->left);
        if(trav->right != NULL)
            enqueue(&Q,trav->right);
    }
    return NULL; // key not found
}

void DFS_Traversal()
{
    stack S;
    init_stack(&S);

    push(&S,root);

    while(!stack_empty(&S))
    {
        struct node* trav = Peek(&S);
        pop(&S);
        printf("%4d",trav->data);
        if(trav->right != NULL)
            push(&S,trav->right);
        if(trav->left != NULL)
            push(&S,trav->left);
    }
}


struct node* Depth_first_search(int key)
{
    stack S;
    init_stack(&S);

    push(&S,root);

    while(!stack_empty(&S))
    {
        struct node* trav = Peek(&S);
        pop(&S);
        if(key == trav->data)
            return trav;
        
        if(trav->right != NULL)
            push(&S,trav->right);
        if(trav->left != NULL)
            push(&S,trav->left);
    }
    return NULL;
    // key not found
}

struct node* BST_Search(int key)
{
    struct node* trav = root;

    while(trav != NULL)
    {
        if(key == trav->data)
            return trav;
        if(key < trav->data)
            trav = trav->left;
        else
            trav = trav->right;
    }
    return NULL; // key not found.
}

struct node* search_with_parent(int key,struct node **p_parent)
{
    *p_parent = NULL;
    struct node *trav = root;

    while(trav != NULL)
    {
        if(key == trav->data)
            return trav;

        *p_parent = trav;
        if(key <trav->data)
            trav = trav->left;
        else
            trav = trav->right;
    }
    *p_parent = NULL;
    return NULL;
}

void delete(int key)
{
    struct node *parent;
    struct node *trav = search_with_parent(key,&parent);

    if(trav == NULL)
    {
        printf("Key not Found !\n");
        return;
    }

    if(trav->left != NULL && trav->right != NULL)
    {
        struct node *succ = trav->right;
        parent = trav;
        while(succ->left != NULL)
        {
            parent = succ;
            succ = succ->left;
        }
        trav->data = succ->data;
        trav = succ;
    }

    if(trav->left == NULL)
    {
        if(trav == root)
            root = trav->right;
        else if(trav == parent->left)
        parent->left = trav->right;
    else
        parent->right = trav->right;
    }

    else //trav->right == NULL)
    {
        if(trav == root)
            root = trav->left;
        else if(trav == parent->left)
            parent->left = trav->left;
        else
            parent->right = trav->left;
    }
    free(trav);
    trav = NULL;
}