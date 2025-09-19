#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int recursion(int i, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
    if (i < 0) return 0;
    
    if (dp[i][w] != -1) return dp[i][w];
    
    int ret = recursion(i - 1, w, val, wt, dp);
    if (wt[i] <= w)
        ret = max(ret, recursion(i - 1, w - wt[i], val, wt, dp) + val[i]);
    
    return dp[i][w] = ret;
}

int tabulation(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = dp[i - 1][j];
            if (wt[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][W];
}

int spaceOptimization(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<int> prev(W + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        vector<int> cur(W + 1);
        for (int j = 0; j <= W; j++) {
            cur[j] = prev[j];
            if (wt[i - 1] <= j) {
                cur[j] = max(cur[j], prev[j - wt[i - 1]] + val[i - 1]);
            }
        }
        prev = cur;
    }
    return prev[W];
}

int spaceOptimizationPlus(int W, vector<int> &val, vector<int> &wt) {
    int n = val.size();
    vector<int> dp(W + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= 0; j--) {
            if (wt[i - 1] <= j) {
                dp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[W];
}

int main() {
    file();

    /*
        Problem Description:
        Find the maximum amount of value that can be gained using a capacity of W,
        for n items of various weights and values.

        Input: 
        The first line contains n, c - the number of items and capacity
        The next line contains n weights for each item.
        The next following line contains n values for each item.

        Time Complexity: O(N * W)

        Space Complexity: O(N * W)

        Space optimization: O(W)
    */
    int n, c;
    cin >> n >> c;

    vector<int> wt(n), val(n);
    for (int &x : wt)
        cin >> x;
    
    for (int &x : val)
        cin >> x;

    cout << spaceOptimizationPlus(c, val, wt) << endl;
    
    return 0;
}