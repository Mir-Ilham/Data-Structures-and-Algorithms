#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main() {
    file();

    /*
        Problem Description:
        Given an array of size N, sort it in ascending order using bubble sort algorithm

        Time Complexity: Avg Case O(N^2), Best Case O(N) 
        Space Complexity: O(1)

    */

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Bubble Sort
    for (int i = n - 1; i >= 1; i--) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                flag = 0;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (flag)
            break;
    }

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}