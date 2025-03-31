#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function for Radix Sort
void countingSortForRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

// Radix Sort function
void radixSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxElement / exp > 0; exp *= 10)
        countingSortForRadix(arr, exp);
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
        cout << "\n1. Sort using Radix Sort\n2. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of elements: ";
                cin >> size;
                arr.resize(size);
                cout << "Enter " << size << " elements: ";
                for (int i = 0; i < size; i++)
                    cin >> arr[i];

                radixSort(arr);
                cout << "Sorted using Radix Sort: ";
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
