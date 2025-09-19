#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int recursive(int cur, int prev, vector<int> &nums, vector<vector<int>> &dp) {
    if (cur == nums.size()) return 0;

    if (dp[cur][prev + 1] != -1) return dp[cur][prev + 1];

    int ret = recursive(cur + 1, prev, nums, dp);

    if (prev == -1 or nums[prev] < nums[cur])
        ret = max(ret, recursive(cur + 1, cur, nums, dp) + 1);
    
    return dp[cur][prev + 1] = ret;
}

int tabulation(vector<int> &nums, vector<vector<int>> &dp) {
    int n = nums.size();

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= -1; j--) {
            int ret = dp[i + 1][j + 1];

            if (j == -1 or nums[j] < nums[i])
                ret = max(ret, dp[i + 1][i + 1] + 1);

            dp[i][j + 1] = ret;
        }
    }

    return dp[0][0];
}

int spaceOptimization(vector<int> &nums) {
    int n = nums.size();

    vector<int> prev(n + 1, 0), cur(n + 1);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= -1; j--) {
            int ret = prev[j + 1];

            if (j == -1 or nums[j] < nums[i])
                ret = max(ret, prev[i + 1] + 1);

            cur[j + 1] = ret;
        }
        prev = cur;
    }

    return prev[0];
}

int main() {
    file();

    /*
        Problem Description:
        Find the Longest Increasing Subsequence length of the given array, nums.

        Input: The first line of input contains the size of nums, n. The next line contains n integers.


        Time Complexity: O(N^2)

        Space Complexity: O(N^2)

        Space optimization: O(N)
    */

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int &x : nums)
        cin >> x;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << spaceOptimization(nums) << endl;
    
    return 0;
}