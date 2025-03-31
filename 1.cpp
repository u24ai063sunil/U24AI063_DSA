#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to partition the array for QuickSelect
int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

// QuickSelect to find kth smallest element
int kthSmallest(vector<int>& arr, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);
        if (pivotIndex == k) return arr[pivotIndex];
        if (pivotIndex > k) return kthSmallest(arr, left, pivotIndex - 1, k);
        return kthSmallest(arr, pivotIndex + 1, right, k);
    }
    return -1;
}

int main() {
    int size, k, choice;
    vector<int> arr;

    do {
        cout << "\n1. Find Kth Smallest Element\n2. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of elements: ";
                cin >> size;
                arr.resize(size);
                cout << "Enter " << size << " elements: ";
                for (int i = 0; i < size; i++)
                    cin >> arr[i];

                cout << "Enter the value of k: ";
                cin >> k;

                if (k > 0 && k <= size)
                    cout << "Kth Smallest Element: " << kthSmallest(arr, 0, size - 1, k - 1) << endl;
                else
                    cout << "Invalid k value!" << endl;
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
