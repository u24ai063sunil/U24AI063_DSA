#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int rollNo;
    char department[50];
} Student;

void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort: Sort by Name, then by Roll No.
void bubbleSort(Student arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0 || 
               (strcmp(arr[j].name, arr[j + 1].name) == 0 && arr[j].rollNo > arr[j + 1].rollNo)) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Binary Search for Student Name
void binarySearch(Student arr[], int n, char key[]) {
    int left = 0, right = n - 1, found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (strcmp(arr[mid].name, key) == 0) {
            printf("Found Record: %s, %d, %s\n", arr[mid].name, arr[mid].rollNo, arr[mid].department);
            found = 1;
            int i = mid - 1;
            while (i >= 0 && strcmp(arr[i].name, key) == 0) {  // Find previous occurrences
                printf("Found Record: %s, %d, %s\n", arr[i].name, arr[i].rollNo, arr[i].department);
                i--;
            }
            i = mid + 1;
            while (i < n && strcmp(arr[i].name, key) == 0) {  // Find next occurrences
                printf("Found Record: %s, %d, %s\n", arr[i].name, arr[i].rollNo, arr[i].department);
                i++;
            }
            return;
        } else if (strcmp(arr[mid].name, key) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("No student found with the name %s\n", key);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    FILE *file = fopen("students.txt", "r");

    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    // Reading student records from the file
    while (fscanf(file, "%[^,], %d, %s\n", students[count].name, &students[count].rollNo, students[count].department) != EOF) {
        count++;
    }
    fclose(file);

    int choice;
    char searchName[50];

    while (1) {
        printf("\nMenu:\n1. Bubble Sort\n2. Binary Search\n3. Quit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(students, count);
                printf("Sorted Student Records:\n");
                for (int i = 0; i < count; i++) {
                    printf("%s, %d, %s\n", students[i].name, students[i].rollNo, students[i].department);
                }
                break;

            case 2:
                printf("Enter Student Name to Search: ");
                scanf("%s", searchName);
                binarySearch(students, count, searchName);
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
