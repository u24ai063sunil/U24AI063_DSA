/* Write a C program to hold two integer pointers as structure members. Allocate space 
for the structure and its data members during runtime. Get one array as input. In the 
second array copy the elements of the first array and replace the odd positioned 
elements by the product of its adjacent elements. Access the array elements and 
structures using pointers instead of subscript notation.
 */
#include <stdio.h>
#include <stdlib.h>

// Structure declaration 
typedef struct 
{
    int *array1; // Pointer to the first array
    int *array2; // Pointer to the second array
} Arrays;

int main() {
    int n; // Size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the structure
    Arrays *arrays = (Arrays *)malloc(sizeof(Arrays));
    if (arrays == NULL) 
    {
        printf("Memory allocation for structure failed.\n");
        return 1;
    }

    // Dynamically allocate memory for the arrays
    arrays->array1 = (int *)malloc(n * sizeof(int));
    arrays->array2 = (int *)malloc(n * sizeof(int));
    if (arrays->array1 == NULL || arrays->array2 == NULL) 
    {
        printf("Memory allocation for arrays failed.\n");
        free(arrays);
        return 1;
    }

    // Input elements into the first array
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", (arrays->array1 + i)); // Pointer arithmetic to access elements
    }

    // Process and copy elements to the second array
    for (int i = 0; i < n; i++) 
    {
        if (i % 2 == 0) 
        {
            // Even-positioned index (odd-positioned element)
            *(arrays->array2 + i) = *(arrays->array1 + i); // Copy directly
        } 
        else 
        { 
            // Odd-positioned index
            if (i > 0 && i < n - 1) 
            {
                *(arrays->array2 + i) = (*(arrays->array1 + i - 1)) * (*(arrays->array1 + i + 1));
            } 
            else 
            {
                *(arrays->array2 + i) = *(arrays->array1 + i); // Edge cases (first/last element)
            }
        }
    }

    // Display the second array
    printf("The elements of the second array are:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", *(arrays->array2 + i));
    }
    printf("\n");

    // Free allocated memory
    free(arrays->array1);
    free(arrays->array2);
    free(arrays);

    return 0;
}
