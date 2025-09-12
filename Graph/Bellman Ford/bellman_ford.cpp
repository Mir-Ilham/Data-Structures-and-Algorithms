#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);



int main() {
    file();

    /*
        Problem Description:
        Given a directed graph that may contain negative weights find the shortest distance
        from source to all nodes in the graph.
        
        If the graph contains a negative weight cycle then output -1

        Input:
        The first line of input contains the value of the total number of nodes and edges n, m.
        The next m lines contain the values of the start and end nodes in an edge followed by its weight.

        Complexity analysis:
        TC: O(V * E)
        SC: O(V)

    */
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edgeList;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back({u, v, w});
    }

    int src = 1;
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto &edge : edgeList) {
            if (dist[edge[0]] + edge[2] < dist[edge[1]])
                dist[edge[1]] = dist[edge[0]] + edge[2];
        }
    }

    int f = 1;
    for (auto &edge : edgeList) {
        if (dist[edge[0]] + edge[2] < dist[edge[1]]) {
            cout << -1 << endl;
            f = 0;
            break;
        }
    }

    if (f) {
        for (int i = 1; i <= n; i++) {
            if (dist[i] >= 1e9) {
                cout << -1 << " ";
                continue;
            }
            cout << dist[i] << " ";
        }
        cout << endl;

        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}