#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int recursive(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if (i < 0 or j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = recursive(i - 1, j - 1, s1, s2, dp) + 1;

    return dp[i][j] = max(recursive(i - 1, j, s1, s2, dp), recursive(i, j - 1, s1, s2, dp));
}

int tabulation(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int ret;
            
            if (s1[i - 1] == s2[j - 1])
                ret = dp[i - 1][j - 1] + 1;
            else
                ret = max(dp[i - 1][j], dp[i][j - 1]);
            
            dp[i][j] = ret;
        }
    }
    return dp[n][m];
}

int spaceOptimization(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    
    vector<int> prev(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        vector<int> cur(m + 1);

        for (int j = 1; j <= m; j++) {
            int ret;
            if (s1[i - 1] == s2[j - 1])
                ret = prev[j - 1] + 1;
            else
                ret = max(prev[j], cur[j - 1]);
            
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
        Given two strings, find the longest common subsequence between these two strings.
        Print the length of LCS.

        Input: Two strings s1 and s2

        Time Complexity: O(N * M)

        Space Complexity: O(N * M)

        Space optimization: O(M)
    */
   
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << spaceOptimization(s1, s2) << endl;
    
    return 0;
}