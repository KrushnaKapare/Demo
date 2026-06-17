#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node* left;
    int data;
    struct node* right;
};

struct node *root = NULL;

struct node* create_node();
void add_node(int data);
void in_order(struct node *trav);
void pre_order(struct node *trav);
void post_order(struct node *trav);

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
    printf("\n\n In-Order Traversal :\n");
    in_order(root);
    printf("\n\n Pre-Order Traversal :\n");
    pre_order(root);
    printf("\n\n Post-Order Traversal :\n");
    post_order(root);
    return 0;
}




struct node* create_node()
{
    struct node *ptr =(struct node*) malloc(sizeof(struct node));

    ptr->data = 0;
    ptr->left = NULL;
    ptr->right = NULL;

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