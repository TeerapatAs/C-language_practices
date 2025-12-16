// C Program to return an array in C using static arrays
#include <stdio.h>

// Function to create and return a static array
int* createStaticArray()
{
    // Declare a static array of size 5
    static int array[5];

    // Initialize the array with example values
    for (int i = 0; i < 5; i++) {
        array[i] = i * 2;
    }

    // Return the pointer to the static array
    return array;
}

int main()
{
    // Call the function to get the static array and store
    // the returned pointer
    int* myArray = createStaticArray();

    // Print the elements of the array
    printf("Array Elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    
    return 0;
}