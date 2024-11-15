#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int n, k;

int recursive(int i, int arr[], vector<int> &dp) {
    if (i == 0) return 0;

    if (dp[i] != -1) return dp[i];

    int cost = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (i - j >= 0) {
            cost = min(cost, abs(arr[i] - arr[i - j]) + recursive(i - j, arr, dp));
        }
    }

    return dp[i] = cost;
}

int iterative(int arr[]) {
    vector<int> dp(n, 0);

    for (int i = 1; i < n; i++) {
        int cost = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                cost = min(cost, abs(arr[i] - arr[i - j]) + dp[i - j]);
            }
        }
        dp[i] = cost;
    }

    return dp[n - 1];
}

int main() {
    file();

    /*
        Problem Description:
        Given an array of size N and max step of K, find the lowest
        cost that can be achieved to move from index 1 to index N.
        Each step from index i to j adds a cost of abs(arr[i] - arr[j])
        to the total cost.

        Constraints:
        2 <= N <= 10^5
        1 <= k <= 100
        1 <= arr[i] <= 10^4

        Time complexity: O(N * K)

        Space complexity: O(N)
    */

    cin >> n >> k;
    
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dp(n, -1);
    cout << recursive(n - 1, arr, dp) << endl;

    cout << iterative(arr) << endl;

    return 0;
}