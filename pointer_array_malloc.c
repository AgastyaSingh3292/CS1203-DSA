#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare a pointer to an array of integers
    int *array;
    
    // Allocate memory for 10 integers using malloc()
    array = (int*)malloc(10 * sizeof(int));
    
    if (array == NULL)
    {
        printf("Error allocating memory!\n");
        return 1;
    }
    
    // Initialize the array
    for (int i = 0; i < 10; i++)
    {
        array[i] = i;
    }
    
    // Print the array
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    // Free the allocated memory using free()
    free(array);
    
    return 0;
}
