#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int recursive(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;

    if (dp[i][j] != -1) return dp[i][j];

    int ret = INT_MAX;
    if (s1[i] == s2[j]) // Match
        return dp[i][j] = recursive(i - 1, j - 1, s1, s2, dp);

    ret = min(ret, recursive(i - 1, j, s1, s2, dp) + 1); // delete
    ret = min(ret, recursive(i, j - 1, s1, s2, dp) + 1); // insert
    ret = min(ret, recursive(i - 1, j - 1, s1, s2, dp) + 1); // replace
    
    return dp[i][j] = ret;
}

int tabulation(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }

            int ret = dp[i - 1][j] + 1;
            ret = min(ret, dp[i][j - 1] + 1);
            ret = min(ret, dp[i - 1][j - 1] + 1);

            dp[i][j] = ret;
        }
    }

    return dp[n][m];
}

int spaceOptimization(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    vector<int> prev(m + 1, 0);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++) {
        vector<int> cur(m + 1, 0);
        cur[0] = i;
        
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cur[j] = prev[j - 1];
                continue;
            }
            int ret = prev[j] + 1;
            ret = min(ret, cur[j - 1] + 1);
            ret = min(ret, prev[j - 1] + 1);
            cur[j] = ret;
        }
        prev = cur;
    }

    return prev[m];
}

int main() {
    file();

    /*
        Problem Description:
        Given two strings s1 and s2, return the minimum number of operations required to convert
        s1 to s2. Operations include: Insert, Delete and Replace

        Input: String s1 and s2


        Time Complexity: O(N * M)

        Space Complexity: O(N * M)

        Space optimization: O(M)
    */

    string s1, s2;
    cin >> s1 >> s2;

    cout << spaceOptimization(s1, s2) << endl;
    
    return 0;
}