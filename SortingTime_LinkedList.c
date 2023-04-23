//Load 1000 random numbers to the text file and load them again on
//linked list and display the time taken to sort the list with the
//sorted list 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    FILE * ft , *f  ;
    clock_t t ;
    ft = fopen ("text.txt" , "w");

    int n , e , u , i;

    int count = 10 ;
    printf("enter the upper limit ");
    scanf ("%d", &u);

    t= clock();

    for (i = 0; i < count; i++) {
      int random = (rand() % (u + 1));
      
      fprintf(ft , "%d ",random );
   }

   fclose (ft) ;

   ft  =  fopen ("text.txt", "r");

    
    

    head = NULL;
    
    for (int i =0; i<count; i++) //load 1000 numbers in the array
    {
        fscanf (ft , "%d",&e );
        head = insert (e);
    }
    printf("Current LL is : ");
    display(head );

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
     t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    printf("The sorting took %f seconds to execute \n", time_taken);

    return head ;
}