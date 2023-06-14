#include <stdio.h>
#include <stdlib.h>

struct node * insert (struct node * , int );
void inorder (struct node * root );
void preorder (struct node * root );
void postorder (struct node * root );

struct node 
{
    int data ;
    struct node *r ;
    struct node *l ;
} *root, *newnode ;

int main ()
{
    int n , ele ;
    root = NULL ;
    printf("Eneter the number of elements in the tree : ");
    scanf ("%d", &n );

    printf("Enter the elements:\n");

    scanf ("%d",&ele);
    root  = insert (root , ele);

    for (int i = 1 ;i < n ; i++)
    {
        scanf ("%d",&ele);
        root = insert (root , ele);
    }

    printf("root->data = %d\n ", root->data);
    printf("Inorder = ");
    inorder (root);

    printf("\nPreorder = ");
    preorder (root);

    printf("\nPostorder = ");
    postorder (root);
}

struct node * new ( int ele)
{
    struct node * node = (struct node *)malloc (sizeof (struct node));
    node->data = ele;
    node->l = NULL ;
    node ->r = NULL ;
    return node ;
}

struct node * insert (struct node * root , int ele)
{

    if (root == NULL)
    {
        return new(ele);
    }

    if (ele < root->data )
    {
        root->l = insert (root->l , ele);
    }

    else if ( ele > root-> data)
    {
        root-> r = insert (root->r , ele);
    }

    //printf("Node Insterted\n");

    return root ;
}

void inorder (struct node * root )
{
    if (root!= NULL)
    {
        inorder (root->l) ;
        printf("%d-> " , root->data);
        inorder (root->r);
    }
}

void preorder (struct node * root )
{
    if (root!= NULL)
    {
        printf("%d-> " , root->data);
        preorder (root->l) ;
        preorder (root->r);
    }
}

void postorder (struct node * root )
{
    if (root!= NULL)
    {
        postorder (root->l) ;
        postorder (root->r);
        printf("%d-> " , root->data);
    }
}