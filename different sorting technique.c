//read the array from the file and sort the array with the sorting technique specified by the user


#include <stdio.h>

void bubblesort (int a[100] , int n );
void selectionsort (int a[] , int n);
void swap (int*  x , int* y );
int partition (int a[], int lb , int ub );
void quicksort (int a[], int lb , int ub);
void InsertionSort (int a[], int n );

int main ()
{
    FILE *f;
    int n , i=0 , a[100], c, lb, ub ;
    f = fopen ("text.txt", "r");

    printf("enter the number of elements u wanna sort ");
    scanf ("%d", &n);

    while (i < n )
    {
        fscanf (f , "%d" , &a[i]);
        i++;
    }
    printf("the array is : ");

    for (i = 0 ;i<n; i++)
    {
        printf("%d ", a[i] );
    }
    printf("\n\n");


    printf("choose the sorting technique \n");
    printf("1 : Bubble sort\n");
    printf("2 : Selection sort \n");
    printf("3 : Quick Sort\n");
    printf("4 : Insertion Sort\n");

    scanf ("%d", &c);

    switch (c)
    {
    case 1:
        bubblesort(a , n);

        break;
    case 2 :
        selectionsort(a, n);
        break ;

    case 3 :
        lb = 0 ;
        ub = n-1;
        quicksort (a,lb, ub);
        break;

    case 4 :
        InsertionSort(a,n);
        break;

    default:
        break;
    }
    printf("Sorted array : ");
    for (i = 0 ;i<n; i++)
    {
        printf("%d ", a[i] );
    }

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

void selectionsort (int a[] , int n)
{
    int i , j , min;

    for (i = 0 ; i< n-1 ; i++)
    {
        min = i ;
        for (j=i+1 ; j<n ; j++)
        {
            if(a[j]< a[min])
            min  = j;
        }

        swap (&a[i], &a[min]);

    }
}

void swap (int*  x , int* y )
{
    int temp = *x;
    *x = *y;
    *y = temp ;
}

int partition (int a[], int lb , int ub )
{
    int pivot = a[lb];
    int start = lb ;
    int end = ub ;
    while (start <end)
    {
        while (a[start] <= pivot )
            start++;

        while (a[end ] > pivot )
            end -- ;
    }


    if(start <end )
    {
        swap (&a[end] , &a[start]);
    }

    else
    {
        swap (&a[lb], &a[end]);
    }

    return end ;
}

void quicksort (int a[], int lb , int ub)
{
    if(lb<ub)
    {
        int loc = partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a, loc+1, ub);
    }

}

void InsertionSort (int a[], int n )
{
    for (int i =1 ; i<n; i++)
    {
        int j =i ;
        int key = a[i];

        while (a[j-1] > key && j>0)
        {
            a[j]= a[j-1];
            j--;
        }
        a[j] = key ;
    }
}
