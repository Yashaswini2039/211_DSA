//Sort the given array using Merge Sort 

#include <stdio.h>

void merge (int a[] , int lb , int mid , int ub )
{
    int i = lb ;
    int j = mid+1 ;
    int k = lb ;
    int b[100];
    
    while ( i <= mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else 
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }

    if(i > mid )
    {
        while (j<=ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }

    else 
    {
        while (i <= mid )
        {
            b[k] = a[i];
            k++;
            i++;
        }
    }

    for (i=0 ; i<=ub ;i++)
    {
        a[i] = b[i];
    }

}

void MergeSort (int a[] , int lb , int ub)
{
    if(lb <ub)
    {
        int mid = (ub+lb)/2 ;
        MergeSort(a, lb, mid );
        MergeSort(a, mid+1 , ub);
        merge (a, lb, mid , ub);
    }
}


int main ()
{
    int a[100], ub, lb ;
    lb= 0 ;
    printf("enter the number of elements: ");
    scanf ("%d",&ub);
    ub--;
    printf("Enter the elements in the array:\n");
    for (int i = 0 ;i<ub+1 ; i++)
    {
        scanf ("%d",&a[i]);
    }
    
    MergeSort(a,lb,ub);
    printf("The Sorted array : ");

    for (int i = 0 ;i<ub+1 ; i++)
    {
        printf("%d ", a[i]);
    }
    
}