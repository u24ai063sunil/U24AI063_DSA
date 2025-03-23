#include <stdio.h>

// Merge function to count inversions
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left, inv_count = 0;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// Merge Sort function to count inversions
int mergeSort(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

// Function to count inversions using Merge Sort
int countInversions(int arr[], int n) {
    int temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}

// Function to take user input
void takeInput(int arr[], int *n) {
    printf("Enter the number of elements: ");
    scanf("%d", n);

    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function with menu-driven switch case
int main() {
    int arr[100], n, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter Array\n");
        printf("2. Count Inversions\n");
        printf("3. Print Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                takeInput(arr, &n);
                break;

            case 2:
                if (n > 0) {
                    printf("Number of inversions: %d\n", countInversions(arr, n));
                } else {
                    printf("Please enter the array first (Option 1).\n");
                }
                break;

            case 3:
                if (n > 0) {
                    printArray(arr, n);
                } else {
                    printf("No array entered yet.\n");
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
