#include <stdio.h>
#include <stdlib.h>

struct node * insert (struct node * , int );
void inorder (struct node * root );
void preorder (struct node * root );
void postorder (struct node * root );
int height (struct node * n );

struct node 
{
    int data ;
    struct node *r ;
    struct node *l ;
    int height ;
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

int max (int a , int b)
{
    return (a>b)? a:b ;
}

int getbalance (struct node * n )
{
    if (n == NULL)
        return 0 ;
    return (height(n->l) - height(n-> r));
}

int height (struct node * n )
{
    if (n ==NULL)
        return 0 ;
    return n->height ;
}

struct node * rightrotate (struct node * y)
{
    struct node* x = y->l ;
    struct node *t2 = x->r ;

    x->r = y ;
    y->l = t2 ;

    y->height = max (height(y->r) , height(y->l)) +1 ;

    x->height = max (height (x->l) , height (x->r)) + 1;

    return x ;
}

struct node * leftrotate (struct node * x)
{
    struct node * y = x->r ;
    struct node * t2 = y->l ;
    y->l = x; 
    x->r = t2 ;

    y->height = max (height(y->l), height (y->r)) +1 ;
    x-> height = max (height (x->r), height (x->l))+1 ;

    return y ;
}



struct node * new ( int ele)
{
    struct node * node = (struct node *)malloc (sizeof (struct node));
    node->data = ele;
    node->l = NULL ;
    node ->r = NULL ;
    node->height = 1 ;
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

    else 
        return root ;

    //printf("Node Insterted\n");

    root->height = 1 + max (height (root->r), height (root->l)) ;

    int balance = getbalance(root) ;

    if (balance > 1 && ele < root->l->data)
    {
        return rightrotate(root);
    }

    if (balance<-1 && ele > root->r->data)
    {
        return(leftrotate(root)) ;
    }

    if (balance>1 && ele > root->l->data)
    {
        root->l = leftrotate(root->l);
        return (rightrotate(root)) ;
    }

    

    if ( balance <-1 && ele < root->r->data)
    {
        root->r = rightrotate(root->r);
        return (leftrotate(root));
    }

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