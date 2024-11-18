#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int recursive(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    
    if (i < 0 || j < 0) return 1e9;

    if (i == 0 and j == 0) return grid[i][j];

    if (dp[i][j] != -1) return dp[i][j];

    int ans = grid[i][j] + recursive(i - 1, j, grid, dp);        // Move up
    ans = min(ans, grid[i][j] + recursive(i, j - 1, grid, dp));  // Move left

    return dp[i][j] = ans;
}

int main() {
    file();

    /*
        Problem Description:
        Given an N X M grid, find the min-cost to reach from the cell (1, 1) to the cell (N, M). 
        Each cell contains an integer that is the associated cost of the cell.

        Valid movements:
        1. Move down
        2. Move right

        Constraints:
        1 <= N * M <= 10^7
        1 <= Matrix[i][j] <= 100

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
        1 2 5
        3 1 1
        3 3 3

        Output: 8

        Test case 2:

        Input:
        3 5
        1 1 5 1 1
        100 1000 1000 1000 1000
        3 3 3 1 1

        Output: 112
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

    return 0;
}