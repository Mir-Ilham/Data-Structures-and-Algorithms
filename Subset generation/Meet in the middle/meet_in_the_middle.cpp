#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main() {
    file();

    /*
        Problem Description:
        Given an array of size N find the number of sub-sequences
        that sum up to X

        Constraints:
        1 <= N <= 30 (N is even)
        1 <= X <= 10^9
        1 <= ai <= 10^9

        Time complexity:
        Let n = N/2,
        O(2^n * n)

        Space complexity: O(2^n)
    */

    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> lset, rset;

    int half = n / 2;
    int subset_ct = 1 << half;

    for (int mask = 0; mask < subset_ct; mask++) {
        int lset_val = 0, rset_val = 0;
        for (int i = 0; i < half; i++) {
            if ((mask & (1 << i)) != 0) {
                lset_val += arr[i];
                rset_val += arr[i + half];
            }
        }
        lset[lset_val]++;
        rset[rset_val]++;
    }

    int ans = 0;
    for (auto p : lset) {
        ans += p.second * (rset[x - p.first]);
    }

    cout << ans << endl;

    return 0;
}