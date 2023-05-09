//Display the sum of the given number

#include <stdio.h>

int sum (int n )
{
    if(n<1)
    {
        return 0 ;
    }

    return (n+sum(n-1));
}

int main ()
{
    int n ;
    printf("Enter the  number: ");
    scanf ("%d",&n);
    int f = sum (n);
    printf("Sum of %d = %d", n , f);
}