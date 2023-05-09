//Display the factorial of the given function

#include <stdio.h>

int factorial (int n )
{
    if(n<=1)
    {
        return 1 ;
    }

    return (n* factorial(n-1));
}

int main ()
{
    int n ;
    printf("Enter the  number: ");
    scanf ("%d",&n);
    int f = factorial (n);
    printf("Factorial of %d = %d", n , f);
}