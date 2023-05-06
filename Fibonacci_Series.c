#include<stdio.h>

int main ()
{
    int a , b , n;
    a=0;
    b=1;
    int c = a+b;

    printf("Enter the number terms in the series: ");
    scanf ("%d",&n);

    printf("Series = ");
    printf("%d %d ", a ,b);
    for (int i=3 ; i<=n ;i++)
    {
        printf("%d ", c);
        a = b;
        b = c ;
        c = a+b;
    }
}
