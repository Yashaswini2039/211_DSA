//Coin change problem
//Display the number of ways it takes to represent a number using the given denomination 

#include <stdio.h>

int change (int d [], int n , int den)
{
    int a[den+1]  ;

    
    int x;

    for (int i =0 ; i<=den ; i++) //initialize array to 0 
    {
        a[i]=0;
    }

    for (int j =0 ; j<n ;j++)
    {
        for (int i = j ; i<= den ;i++)
        {
            if (i == 0 )
            {
                a[i]=1;
            }

            else if (i<d[j]);

            else 
            {
                x = i - d[j];
                a[i] = a[i] + a[x];
            }

        }
    }

    // for (int i =0 ; i<=den ; i++) //Remove coments to print the look up table 
    // {
    //     printf("%d ", a[i]);
    // }
    //printf("\n");

    return a[den];

}

int main ()
{
    int n  ,a[100], den;
    printf("Enter the number of denomination :");
    scanf ("%d" ,&n);

    printf("Enter the value of coins you have: ");
    for (int i =0 ; i<n ;i++)
    {
        scanf ("%d" ,&a[i]);
    }

    printf("Enter the value you want to obtain using the coins with above denomination : ");
    scanf ("%d" ,&den);
    int f = change (a , n , den);

    printf("The total number of combinations that will sum up to %d is %d", den , f);
}