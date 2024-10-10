#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int binarySearch(vector<int> &arr, int target) {
    int l = 0, r = arr.size() - 1;

    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    if (arr[l] == target)
        return l;
    else if (arr[r] == target)
        return r;
    else
        return -1;
}

int main() {
    file();

    /*
        Problem Description:
        Given a sorted array of size N,
        check for each query if target exists in the array or not.
        Print its index if it does else print -1.

        Constraints:
        1 <= N <= 1e5
        1 <= Q <= 1e5

        Time Complexity: O(logN)

        Space Complexity: O(1)
    */

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int q;
    cin >> q;

    while (q--) {
        int target;
        cin >> target;

        cout << binarySearch(arr, target) << endl;

        /*
            STL binary search algorithm returns true if target exists
            in array else false

            binary_search(arr.begin(), arr.end(), target);
        */
    }

    return 0;
}