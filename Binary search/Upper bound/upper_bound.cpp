#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int upperBound(vector<int> &arr, int x) {
    // Time Complexity: O(logN)
    // Space Complexity: O(1)

    int l = 0, r = arr.size() - 1;

    while (r - l > 1) {
        int mid = (r + l) / 2;

        if (arr[mid] <= x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    if (arr[l] > x)
        return l;
    else if (arr[r] > x)
        return r;
    else
        return arr.size();
}

int main() {
    file();

    /*
        Problem Description:
        Given a sorted array of size N find the highest index
        such that if X is inserted in that index the array will remain sorted.
        Answer Q queries for different values of X.

        Constraints:
        1 <= N <= 1e5
        1 <= Q <= 1e5
    */

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;

        cout << upperBound(arr, x) << endl;

        /*
            STL upper-bound algorithm returns iterator

            auto it = upper_bound(arr.begin(), arr.end(), x);
            int index = it - arr.begin();
            int ub_val = *it;
        */

    }

    return 0;
}