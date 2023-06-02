#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100

int full (int n);
int empty (int n );
void enq (int , int);
void deq (int );
void display (int );

int q[MAX] , f= -1 , r =-1 ;

int main ()
{
    FILE * ft , *file;
    ft = fopen ("text.txt", "w");
    int count  = 1000 ;
    int u , i , ch, n , en, pu, po;
    n = MAX ;

    printf("Enter the upper limit: ");
    scanf ("%d", &u );

    for (i = 0 ; i<u ; i++)
    {
        int random  = (rand() % (u+1));
        fprintf(ft , "%d ", random );
    }

    fclose (ft );

    file = fopen ("copy.txt" , "w");
    printf("Number of pushes:");
    scanf ("%d",&pu);
    fprintf(file , "%d ", pu);

    printf("Number of pops:");
    scanf ("%d",&po);
    fprintf(file , "%d ", po);

    fclose (file);
    
    file = fopen ("copy.txt", "r");
    ft = fopen ("text.txt", "r");

    fscanf (file , "%d", &pu) ;
    fscanf (file , "%d", &po);

    for (int i = 0 ;i< pu ;i++)
    {
        fscanf (ft , "%d", &en);
        enq (n, en);
    }

    for (int i = 0 ;i<po ; i++)
    {
        deq(n);
    }

    fclose (ft);
    fclose (file);
}

void enq (int n , int en )
{
    FILE *qu , *pu , *op ;
    qu = fopen ("queue.txt", "a+");
    pu = fopen ("enqueue.txt", "a");
    op = fopen ("operation.txt", "a");

    if (full (n))
    {
        printf("\nOverloaded\n");
    }

    else
    {
        if (f==-1)
            f++;

        r=(r+1) % n;
        q[r] = en ;
        fprintf(qu , "%d\n", q[r]);
        fprintf(pu , "%d\n", q[r]);
        fprintf(op , "Enqueue( %d )\n", q[r]);
    }

    fclose (qu);
    fclose (pu);
    fclose (op);
}

int full (int n)
{
    if ((f== r+1) || (f==0 && r==n-1) )
        return 1 ;

    return 0 ;
}

void deq (int n )
{
    FILE *qu , *po , *op ;

    qu = fopen("queue.txt", "a+");
    po = fopen ("pop.txt", "a");
    op = fopen ("operation.txt", "a");

    if (empty(n))
    {
        printf("\nQueue is empty\n");
        fprintf(op , "Queue is empty\n");
    }
    else
    {
        printf("element dequeued = %d\n", q[f] );
        fprintf(po , "%d\n",q[f]);
        fprintf(op , "Dequeued( %d )\n", q[f]);

        if (f==r)
        {
            f=-1;
            r=-1;
        }

        else
            f = (f+1)%n ;
    }
    fclose (qu);
    fclose (po);
    fclose (op);
}

int empty (int n )
{
    if (f==-1 && r==-1 )
    return 1 ;

    return 0 ;
}

void display (int n)
{
    int temp = f ;

    if (empty (n))
    printf("\nQueue is empty\n");

    else
    {
        while (temp != r)
        {
            printf("%d-> ", q[temp]);
            temp = (temp+1) % n;
        }

        printf("%d\n", q[temp]);

    }
}
