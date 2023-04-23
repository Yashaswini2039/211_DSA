//Read the 1st element from the text file and print those many elements 

#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data ;
    struct node * next ;
} *head , *new, *temp, *temp1;

struct node * insert (int n );
void display (struct node * head );


int main ()
{
    FILE * ft ;
    ft = fopen ("text.txt" , "r");

    int n , e;

    fscanf (ft , "%d", &n);

    head = NULL;
    for (int i =0; i<n; i++)
    {
        fscanf (ft , "%d",&e );
        head = insert (e);
    }
    printf("current ll is : ");
    display (head );
    printf("\n");

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

