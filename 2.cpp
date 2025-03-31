#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Counting Sort function
void countingSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());
    vector<int> count(maxElement + 1, 0);

    for (int num : arr) count[num]++;
    int index = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

// Function to display the sorted array
void displayArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    int size, choice;
    vector<int> arr;

    do {
        cout << "\n1. Sort using Counting Sort\n2. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of elements: ";
                cin >> size;
                arr.resize(size);
                cout << "Enter " << size << " elements: ";
                for (int i = 0; i < size; i++)
                    cin >> arr[i];

                countingSort(arr);
                cout << "Sorted using Counting Sort: ";
                displayArray(arr);
                break;

            case 2:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 2);

    return 0;
}
