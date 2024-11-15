#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int fib_recursive(int n) {
    if (n < 2) return n;

    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_recursive_dp(int n, vector<int> &dp) {
    if (n < 2) return n;

    if (dp[n] != -1) return dp[n];

    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int fib_tabulation(int n) {
    if (n < 2) return n;

    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    return dp[n];
}

int fib_space_optimized(int n) {
    if (n < 2) return n;

    int prev2 = 0, prev1 = 1, cur; 

    for (int i = 2; i <= n; i++) {
        cur = prev1 + prev2;
        prev2 = prev1;
        prev1 = cur;
    }
    
    return prev1;
}

int main() {
    file();

    /*
        Problem Description:
        
        Print the nth fibonacci number.
        Example fibonacci sequence: 0 1 1 2 3 5 8 13 21 ...
        Sequence with zero based index.

        Constraints:
        1 <= N <= 20

        Time Complexity: O(N)

        Space Complexity: O(N)
    */

    int n;
    cin >> n;

    cout << fib_recursive(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << fib_recursive_dp(n, dp) << endl;

    cout << fib_tabulation(n) << endl;

    cout << fib_space_optimized(n) << endl;

    return 0;
}