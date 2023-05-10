#include<stdio.h>
//To find the number of ways in which the numbers on n dice with m sides will sum up to x 

int sum ( int n ,int x , int m)
{
    //n = num of dice 
    //x = the number to be obtained
    //m = num of faces

    int t[n+1][x+1] ;
    for (int i = 0 ;i<=n ; i++) //initializing the matix to 0
    {
        for (int j = 0 ;j <=x; j++)
        {
            t[i][j] = 0;
        }
    }
    //for just 1 dice 
    for (int i =1 ;i<=m ; i++) //excluding the 0th position 
    {
            t[1][i] = 1;
    }    

    for (int i = 2 ; i<= n ; i++)
    {
        for (int j = 1 ; j<=x ; j++)
        {
            for (int k =1 ; k<j && k <=m ; k++)
            {
                t[i][j] = t[i][j] + t[i-1][j-k];
            }
        }
    }

    
    
    // for (int i = 1 ; i<=n ; i++)  // Remove these coments to view the lookup table 
    // {
    //     for (int j = 1 ; j<=x  ; j++)
    //     {
    //         printf("%d ", t[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    return t[n][x];
}

int main ()
{
    int n ,m ,x;
    printf("Enter the number of dice:");
    scanf ("%d", &n);

    printf ("Enter the num of sides on each dice : ");
    scanf ("%d" ,&m);

    printf("Enter the number to be obtained : ");
    scanf ("%d" ,&x);

    int f = sum (n , x , m);

    printf("The number of ways = %d\n" ,f);
}