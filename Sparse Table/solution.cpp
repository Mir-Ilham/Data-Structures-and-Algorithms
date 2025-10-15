#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

void solve()
{   
    int n, q;
    cin >> n >> q;

    int LG = log2(n);

    vector<vector<int>> M(n, vector<int>(LG + 1));

    for (int i = 0; i < n; i++)
        cin >> M[i][0];

    for (int j = 1; j <= LG; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            M[i][j] = min(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int len = r - l + 1;
        // Optimization to find K leads to O(Q) overall for queries
        int k = 0;
        while ((1 << (k + 1)) <= len)
            k++;
        int res = min(M[l][k], M[r - (1 << k) + 1][k]);
        cout << res << endl;
    }
}
 
int32_t main()
{   
    /*
        Problem Statement: https://cses.fi/problemset/task/1647
        
        Algorithm: Sparse Table, can be used to find static min, max and GCD range queries

        TC: O(N*logN) + O(Q*logN)
        Log precomputation leads to O(Q) for queries

        SC: O(N*logN)
    */
    
    optimize();
    // file();     
    solve();
    return 0;
}