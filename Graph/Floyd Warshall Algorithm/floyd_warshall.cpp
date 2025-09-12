#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);



int main() {
    file();

    /*
        Problem Description:
        The problem is to find the shortest distances between every pair of vertices 
        in a given edge-weighted directed graph. 

        Input:
        The graph is represented as an adjacency matrix of size n*n.
        Matrix[i][j] denotes the weight of the edge from i to j. 
        If Matrix[i][j]=-1, it means there is no edge from i to j.

        The first line of input contains n. The next n lines contain each row of the adjacency matrix.

        Complexity analysis:
        TC: O(N^3)
        SC: O(N^2)

    */
    int n;
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
            if (adjMatrix[i][j] == -1)
                adjMatrix[i][j] = 1e9;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (adjMatrix[i][i] < 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == 1e9) {
                cout << -1 << " ";
            } else {
                cout << adjMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}