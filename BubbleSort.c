//Sort the given array using Bubble sort

#include <stdio.h>

void swap (int*  x , int* y )
{
    int temp = *x;
    *x = *y;
    *y = temp ;
}

void bubblesort (int a[100] , int n )
{
    int i , j , temp ;
    int *x , *y ;

    for (i = 0 ;i<n-1 ; i++)
    {
        for (j=0 ; j<n-i-1 ; j++)
        {
            if(a[j]>a[j+1])
            {
                x  = &a[j];
                y = &a[j+1];
                swap (x,y);
            }
        }
    }
}

int main ()
{
    int a[100];
    int n  ;
    printf("Enter the number of elements to be sorted : ");
    scanf ("%d",&n);

    printf("Enter the elements in the array\n");
    for (int i =0 ;i<n ;i ++)
    {
        scanf ("%d",&a[i]);
    }

    bubblesort(a,n);

    printf("The sorted array : ");
    for (int i =0 ;i<n ; i++)
    {
        printf("%d " , a[i]);
    }
}
