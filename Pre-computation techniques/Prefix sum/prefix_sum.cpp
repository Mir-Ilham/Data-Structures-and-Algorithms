#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main() {
    file();

    /*
        Problem Description:
        Given an array of size N find the sum of the sub-array 
        starting at l and ending at r provided by each query.

        Constraints:
        1 <= N <= 10^5
        1 <= Q <= 10^5
    */

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int prefix[n + 1];
    prefix[0] = 0;

    for (int i = 1; i <= n; i++) {
        prefix[i] = arr[i - 1] + prefix[i - 1];
    }

    int query;
    cin >> query;

    while (query--) {
        int l, r;
        cin >> l >> r;

        cout << prefix[r] - prefix[l-1] << endl;
    }

    return 0;
}