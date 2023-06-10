#include <stdio.h>
#include <stdlib.h>

struct node * insert (struct node * , int, int  );
void inorder (struct node * root );
void preorder (struct node * root );
void postorder (struct node * root );

struct node
{
    int data ;
    int flag ;
    struct node *r ;
    struct node *l ;
} *root, *newnode ;

FILE * in, * pre, *post ;

int main ()
{
    FILE* ft, *alpha ;

    ft = fopen ("text.txt", "w");
    int u , i,n , ele, r[100]  ;

    printf("Eneter the number of elements in the tree : ");
    scanf ("%d", &n );

    printf("enter the upper limit: ");
    scanf ("%d", &u);

    for (i = 0; i < n; i++)
    {
      int random = (rand() % (u + 1));
      fprintf(ft , "%d ",random );
    }
    fclose(ft);

    alpha = fopen ("alpha.txt", "w");
    for (i = 0 ; i<n+1 ; i++)
    {
        int random = (rand() % 26) + 65; // 65 - 90 ---> (90-65+1) 
        fprintf(alpha , "%c",random );
    }
    fclose (alpha);
    alpha = fopen ("alpha.txt" ,"r");
    ft = fopen ("text.txt", "r");
    root = NULL ;

    for (i = 0; i < n; i++)
    {
      r[i] = (rand() % 2);
    }

    for (i = 0; i < n; i++)
    {
      printf("%d ", r[i]);
    }
    int k = 0 ;

    if (r[k] == 1)
        fscanf (ft, "%d",&ele);
    else
        fscanf (alpha, "%c",&ele);

    k++;
    root  = insert (root , ele, r[k]);

    for (int i = 1 , k= 1 ;i < n ; i++, k++)
    {
        if (r[k] == 1)
        fscanf (ft, "%d",&ele);

        else
        fscanf(alpha , "%c", &ele);

        insert (root , ele , r[k]);
    }

    //printf("\nroot->data = %d\n ", root->data);
    printf("\nInorder = ");
    inorder (root);

    printf("\nPreorder = ");
    preorder (root);

    printf("\nPostorder = ");
    postorder (root);
}

struct node * new ( int ele, int f)
{
    struct node * node = (struct node *)malloc (sizeof (struct node));
    node->data = ele;
    node->flag = f ;
    node->l = NULL ;
    node ->r = NULL ;
    return node ;
}

struct node * insert (struct node * root , int ele, int f)
{

    if (root == NULL)
    {
        return new(ele, f);
    }

    if (ele < root->data )
    {
        root->l = insert (root->l , ele, f);
    }

    else if ( ele > root-> data)
    {
        root-> r = insert (root->r , ele,f);
    }

    //printf("Node Insterted\n");

    return root ;
}

void inorder (struct node * root )
{
    if (root!= NULL)
    {
        inorder (root->l) ;
        in = fopen ("inorder.txt", "a");
        if (root->flag == 1)
        {
            printf("%d " , root->data);
            //printf("%d -> " , root->flag);
            fprintf(in , "%d-> " , root->data);
        }

        else
        {
            printf("%c " , root->data);
            //printf("%d -> " , root->flag);
            fprintf(in , "%c-> " , root->data);
        }

        fclose (in);
        inorder (root->r);
    }
}

void preorder (struct node * root )
{
    if (root!= NULL)
    {
        pre = fopen ("preorder.txt", "a");
        // printf("%d " , root->data);
        // printf("%d -> " , root->flag);
        // fprintf(pre , "%d-> " , root->data);

        if (root->flag == 1)
        {
            printf("%d " , root->data);
            //printf("%d -> " , root->flag);
            fprintf(pre , "%d-> " , root->data);
        }

        else
        {
            printf("%c " , root->data);
            //printf("%d -> " , root->flag);
            fprintf(pre , "%c-> " , root->data);
        }

        fclose (pre);
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
        post = fopen ("postoder.txt", "a");
        // printf("%d " , root->data);
        // printf("%d -> " , root->flag);
        // fprintf(post , "%d-> " , root->data);

        if (root->flag == 1)
        {
            printf("%d " , root->data);
            //printf("%d -> " , root->flag);
            fprintf(post , "%d-> " , root->data);
        }

        else
        {
            printf("%c " , root->data);
            //printf("%d -> " , root->flag);
            fprintf(post , "%c-> " , root->data);
        }

        fclose (post);
    }
}
