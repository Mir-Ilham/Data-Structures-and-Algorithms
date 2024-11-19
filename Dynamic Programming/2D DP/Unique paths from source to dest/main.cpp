#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int recursive(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    
    if (i < 0 || j < 0 || grid[i][j] == 1) return 0;

    if (i == 0 and j == 0) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = recursive(i - 1, j, grid, dp);    // Move up
    ans += recursive(i, j - 1, grid, dp);       // Move left

    return dp[i][j] = ans;
}

int tabulation(vector<vector<int>> &grid) {
    
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    dp[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 and  j == 1) continue;

            if (grid[i - 1][j - 1] == 1) continue;

            int ans = dp[i - 1][j];    // Move up
            ans += dp[i][j - 1];       // Move left

            dp[i][j] = ans;
        }
    }

    return dp[n][m];
}

int tabulation_space_optimized(vector<vector<int>> &grid) {
    
    int n = grid.size(), m = grid[0].size();

    vector<int> prev(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        vector<int> cur(m + 1, 0);
        
        if (i == 1)
            cur[1] = 1;

        for (int j = 1; j <= m; j++) {
            if (i == 1 and  j == 1) continue;

            if (grid[i - 1][j - 1] == 1) continue;

            int ans = prev[j];    // Move up
            ans += cur[j - 1];    // Move left

            cur[j] = ans;
        }
        prev = cur;
    }

    return prev[m];
}

int main() {
    file();

    /*
        Problem Description:
        Given an N X M grid, find the number of unique paths to reach from the cell (1, 1) to the cell (N, M). 
        Each cell contains an integer that is either 1 or 0. Here 0 indicates an empty space and 1 indicates
        a blocked cell.

        Valid movements:
        1. Move down
        2. Move right

        Constraints:
        1 <= N, M <= 10^3
        grid[i][j] is 0 or 1

        Time Complexity:
        O(N * M)

        Space Complexity:
        O(N * M)
        Optimization: O(M)
    */

    /*
        Test case 1:

        Input:
        3 3
        0 0 0
        0 1 0
        0 0 0

        Output: 2

        Test case 2:

        Input:
        3 3
        0 0 0
        0 0 0
        0 1 0

        Output: 3
    */

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << recursive(n - 1, m - 1, grid, dp) << endl;

    cout << tabulation(grid) << endl;

    cout << tabulation_space_optimized(grid) << endl;

    return 0;
}