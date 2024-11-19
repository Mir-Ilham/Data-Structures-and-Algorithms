#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int recursive(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    if (i == j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        int steps = arr[i - 1] * arr[k] * arr[j];
        steps += recursive(i, k, arr, dp) + recursive(k+1, j, arr, dp);
        ans = min(steps, ans);
    }

    return dp[i][j] = ans;
}

int tabulation(int n, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i > 0; i--) {
        for (int j = i + 1; j < n; j++) {
            int ans = INT_MAX;
            for (int k = i; k < j; k++) {
                int steps = arr[i - 1] * arr[k] * arr[j];
                steps += dp[i][k] + dp[k+1][j];
                ans = min(steps, ans);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][n - 1];
}

int main() {
    file();

    /*
        Problem Description:
        Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
        The efficient way is the one that involves the least number of multiplications. 
        The dimensions of the matrices are given in an array arr[] of size n (such that n = number of matrices + 1) 
        where the ith matrix has the dimensions (arr[i-1] x arr[i]).

        Constraints:
        2 <= n <= 100
        1 <= arr[i] <= 500

        Time Complexity: O(N^3)

        Space Complexity: O(N^2)

        Space optimization: O(N)
    */

    /*
        Test case 1:
        Input:
        4
        2 1 3 4
        Output: 20

        Test case 2:
        Input:
        5
        1 2 3 4 3
        Output: 30

        Test case 3:
        Input:
        2
        3 4
        Output: 0
    */
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << recursive(1, n-1, arr, dp) << endl;

    cout << tabulation(n, arr) << endl;
    
    return 0;
}