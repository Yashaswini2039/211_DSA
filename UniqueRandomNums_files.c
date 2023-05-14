#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isUnique(int number, int* array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return 0; // Not unique
        }
    }
    return 1; // Unique
}

int main() {

    FILE * ft;
    ft = fopen ("text.txt", "w");

    int maxRange; // Maximum range for random number
    printf("Enter the maxmum range: ");
    scanf ("%d",&maxRange);

    int numElements; // Number of unique random numbers to generate
    printf("Enter the number of elements:");
    scanf ("%d",&numElements);

    if (maxRange<numElements)
    {
        printf("Error: maximum range less than Number of elements");
        exit (0);
    }

    // Seed the random number generator
    srand(time(NULL));

    int randomArray[numElements];
    int count = 0;

    while (count < numElements) {
        int randomNumber = rand() % maxRange + 1;
        
        if (isUnique(randomNumber, randomArray, count)) {
            randomArray[count] = randomNumber;
            count++;
        }
    }

    printf("Unique random numbers: ");
    for (int i = 0; i < numElements; i++) {
        fprintf(ft , "%d ", randomArray[i]);
        printf("%d ", randomArray[i]);
    }
    printf("\n");

    fclose (ft);

    return 0;
}