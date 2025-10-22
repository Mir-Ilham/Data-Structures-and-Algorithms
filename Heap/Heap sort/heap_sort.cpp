#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

void heapify(vector<int> &arr, int n, int i, function<bool(int, int)> compare) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    // Check if left child is larger
    if (left < n && compare(arr[left], arr[largest]))
        largest = left;

    // Check if right child is larger
    if (right < n && compare(arr[right], arr[largest]))
        largest = right;

    // If largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, compare);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    // Sort ASCENDING
    function<bool(int, int)> compare = [](int a, int b) { return a > b; };

    // Step 1: Build max heap
    for (int i = n / 2 - 1; i > 0; i--)
        heapify(arr, n, i, compare);

    // Step 2: Extract elements one by one
    for (int i = n-1; i > 1; i--) {
        swap(arr[1], arr[i]);
        heapify(arr, i, 1, compare);
    }
}

int main() {
    file();

    /*
        Problem Description: Implementation of heap sort

        Input:
        The first line of input includes the number of nodes n.
        The next line contains values for n nodes.
    */

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
