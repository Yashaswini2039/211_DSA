//Generate random numbers and store it in text file and push the numbers on to the queue file and also pushed elemeys must be stored
//in push and enqueue elements in dequeue file and all these operations must be stored in operation_queue file.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

void enq (int n );
void deq ();
void display ();

int q[MAX], f=-1 , r= -1;

int main()
{
    FILE * ft;
    ft = fopen("text.txt", "w");
    int u , i,ch, n;
    int count = 1000;

    printf("enter the upper limit ");
    scanf ("%d", &u);

    for (i = 0; i < count; i++)
    {
      int random = (rand() % (u + 1));
      fprintf(ft , "%d ",random );
   }
    fclose(ft);

    ft = fopen ("text.txt", "r");

    while (1)
    {
    printf("1: Enqueue \n");
    printf("2: Dequeue\n");

    printf("Enter the choice:");
    scanf ("%d" ,&ch);


        switch(ch)
        {
            case 1 :
                {
                    fscanf (ft , "%d", &n);
                    enq (n);
                }
                break ;
            case 2 : deq();
                break;
            default: display ();
        }

    }

    fclose (ft);
}

void enq (int n )
{
    FILE  *pu,*f , *op;

    f = fopen ("queue.txt", "a+");
    pu = fopen ("enqueue.txt", "a");
    op = fopen ("operation.txt" , "a");

    if ( r == MAX-1 )
    {
        printf("Queue is full\n");
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }
        r++ ;
        q[r] = n ;
        fprintf(f , "%d\n", q[r]);
        fprintf(pu , "%d\n", q[r]);
        fprintf(op , "Enqueue( %d )\n", q[r]);
    }


    fclose (f);
    fclose (pu);
    fclose (op);



}

void deq ()
{
    FILE *fl, *po ,*op ;

    fl= fopen ("stackFile.txt", "a");
    po = fopen ("pop.txt", "a");
    op = fopen ("operation.txt" , "a");

    if (r == -1)
    {
        printf("Queue is empty\n");
    }

    else
    {
        if (f == r)
        {
            printf("Removed %d\n", q[f]);
            fprintf(po , "%d\n",q[f]);
            fprintf(op , "Dequeued( %d )\n", q[f]);
            f=-1;
            r=-1;
        }

        else
        {
            printf("Removed %d\n", q[f]);
            fprintf(po , "%d\n",q[f]);
            fprintf(op , "Dequeued( %d )\n", q[f]);
            f++;
        }

    }

    fclose (fl);
    fclose (po);
    fclose (op);

}

void display ()
{
    for (int i = f ;i<= r ; i++)
    {
        printf("%d ", q[i] );
    }

    // int temp = top;
    // if (top ==-1)
    // {
    //     printf("Underflow \n");
    // }
    // else
    // {
    //     for (int i = temp ;i>-1 ; i--)
    //     {
    //         printf("%d\n", stack[i]);
    //     }
    // }
}
