//Read the 1st element from the text file and sort those elements and print it 

#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data ;
    struct node * next ;
} *head , *new, *temp, *temp1;

struct node * insert (int n );
void display (struct node * head );
struct node * sort (int n );

int main ()
{
    FILE * ft ;
    ft = fopen ("text.txt" , "r");

    int n , e;

    //printf("enter the elemets in the list ");
    fscanf (ft , "%d", &n);

    head = NULL;
    //printf("enter the nums in the list ");
    for (int i =0; i<n; i++)
    {
        fscanf (ft , "%d",&e );
        head = insert (e);
    }
    printf("current ll is : ");
    display (head );
    printf("\n");

    head = sort (n);

    printf("the sorted list is : ");
    display(head );

}

struct node * insert (int n )
{
    new = (struct node*)malloc (sizeof(struct node));

    new->data = n ;

    if(head == NULL)
    {
        head = new ;
        new->next = NULL;
    }

    else 
    {
        temp = head ;

        while (temp->next != NULL)
        {
            temp = temp->next ;
        }

        temp->next = new ;
        new ->next = NULL;
    }

    return head ;
}

void display (struct node * head )
{
    temp =head ;
    while (temp!=NULL)
    {
        printf("%d ", temp->data );
        temp = temp->next ;
    }
}

struct node * sort (int n )
{
    int t ;
    for (int i = 0 ; i<n; i++)
    {
        for (temp = head , temp1 = temp->next ; temp1 != NULL ; temp = temp->next , temp1= temp1->next )
        {
            if(temp->data  > temp1->data )
            {
                t  = temp->data ;
                temp->data = temp1->data ;
                temp1->data = t;
            }
        }
    }

    return head ;
}