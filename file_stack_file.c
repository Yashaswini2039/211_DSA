//Read the input from the user and store it in file and then retive it again and do the previous operations

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

void push ();
void pop ();


int stack[MAX], top = -1;

int main()
{
    FILE * ft, *file;
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
    file = fopen ("copy.txt" , "w");

    while (1)
    {
        printf("1: Push \n");
        printf("2: Pop \n");
        printf("3: Exit\n");
        printf("Enter the choice:");
        scanf ("%d" ,&ch);
        fprintf(file , "%d ", ch);
        if (ch==3)
            break;
    }
    fclose (file);

    file = fopen ("copy.txt", "r");

    ft = fopen ("text.txt", "r");

    while (EOF)
    {
        fscanf (file , "%d", &ch);

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

        }

    }

    fclose (ft);
    fclose (file);
}

void push (int n )
{
    FILE  *pu,*f , *op;

    f = fopen ("stackFile.txt", "a+");
    pu = fopen ("push.txt", "a");
    op = fopen ("operation.txt" , "a");

    if (top == MAX-1 )
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack[top] = n;
        fprintf(f , "%d\n", stack[top]);
        fprintf(pu , "%d\n", stack[top]);
        fprintf(op , "PUSH( %d )\n", stack[top]);
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

    if (top ==-1)
    {
        printf("Unterflow\n");
    }
    else
    {
        fprintf(po , "%d\n",stack[top]);
        fprintf(op , "POP( %d )\n", stack[top]);

        top--;
    }

    fclose (f);
    fclose (po);
    fclose (op);

}

