//Generate random numbers and store it in text file and push the numbers on to the stackFile file and also pushed elemeys must be stored
//in push and poped elements in pop file and all these operations must be stored in operation filr.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

void push ();
void pop ();
void display ();

int stack[MAX], top = 0;

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
    printf("1: Push \n");
    printf("2: Pop \n");

    printf("Enter the choice:");
    scanf ("%d" ,&ch);


        switch(ch)
        {
            case 1 :
                {
                    fscanf (ft , "%d", &n);
                    push (n);
                }
                break ;
            case 2 : pop();
                break;
            default: display ();
        }

    }

    fclose (ft);
}

void push (int n )
{
    FILE  *pu,*f , *op;

    f = fopen ("stackFile.txt", "a+");
    pu = fopen ("push.txt", "a");
    op = fopen ("operation.txt" , "a");

    if (top == MAX )
    {
        printf("Overflow\n");
    }
    else
    {
        stack[top] = n;
        fprintf(f , "%d\n", stack[top]);
        fprintf(pu , "%d\n", stack[top]);
        fprintf(op , "PUSH( %d )\n", stack[top]);
        top++;
    }


    fclose (f);
    fclose (pu);
    fclose (op);



}

void pop ()
{
    FILE *f, *po ,*op ;

    f= fopen ("stackFile.txt", "a");
    po = fopen ("pop.txt", "a");
    op = fopen ("operation.txt" , "a");

    if (top ==0)
    {
        printf("Unterflow\n");
    }
    else
    {
        top--;
        fprintf(po , "%d\n",stack[top]);
        fprintf(op , "POP( %d )\n", stack[top]);

    }

    fclose (f);
    fclose (po);
    fclose (op);

}

void display ()
{
    int temp = top;
    if (top ==-1)
    {
        printf("Underflow \n");
    }
    else
    {
        for (int i = temp ;i>-1 ; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

