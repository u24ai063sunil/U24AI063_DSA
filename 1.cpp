#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<int>& arr, int bucketCount) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;
    int bucketSize = (range + bucketCount - 1) / bucketCount;

    vector<vector<int>> buckets(bucketCount);

    for (int num : arr) {
        int index = (num - minVal) / bucketSize;
        buckets[index].push_back(num);
    }

    arr.clear();
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    bucketSort(arr, 7);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
