#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];

    int i = low, j = high;
    while (i < j) {
        while (arr[i] <= pivot and i < high)
            i++;
        while (arr[j] > pivot and j > low)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[j], arr[low]);
    
    return j;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    file();

    /*
        Problem Description:
        Given an array of size N, sort it in ascending order using quick sort algorithm

        Time Complexity: Best case: O(NlogN)
        Space Complexity: O(1)

    */

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}