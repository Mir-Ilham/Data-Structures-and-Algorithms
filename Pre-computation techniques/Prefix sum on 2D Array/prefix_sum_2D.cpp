#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main() {
    file();

    /*
        Problem Description:
        Given a grid of size N X M find the sum of the values in the sub-grid
        starting at r1, c1 and ending at r2, c2 provided by each query.

        Constraints:
        1 <= N, M <= 100
        1 <= Q <= 10^5
    */

    int n, m;
    cin >> n >> m;

    int grid[n + 1][m + 1], prefix[n + 1][m + 1] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + grid[i][j];
        }
    }

    int query;
    cin >> query;

    while (query--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        cout << prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] + prefix[r1 - 1][c1 - 1] << endl;
    }

    return 0;
}