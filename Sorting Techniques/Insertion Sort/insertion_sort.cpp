#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main() {
    file();

    /*
        Problem Description:
        Given an array of size N, sort it in ascending order using insertion sort algorithm

        Time Complexity: Worst and Avg case O(N^2), Best Case O(N)
        Space Complexity: O(1)

    */

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Insertion Sort
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0 and arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}