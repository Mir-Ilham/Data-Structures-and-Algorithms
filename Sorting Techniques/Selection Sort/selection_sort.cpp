#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main() {
    file();

    /*
        Problem Description:
        Given an array of size N, sort it in ascending order using selection sort algorithm

        Time Complexity: O(N^2)
        Space Complexity: O(1)

    */

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini])
                mini = j;
        }
        swap(arr[mini], arr[i]);
    }

    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}