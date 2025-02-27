#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;

    int left = low, right = mid + 1;

    while (left <= mid and right <= high) {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    
    while (left <= mid)
        temp.push_back(arr[left++]);
    
    while (right <= high)
        temp.push_back(arr[right++]);
    
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main() {
    file();

    /*
        Problem Description:
        Given an array of size N, sort it in ascending order using merge sort algorithm

        Time Complexity: O(NlogN)
        Space Complexity: O(N)

    */

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n-1);

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}