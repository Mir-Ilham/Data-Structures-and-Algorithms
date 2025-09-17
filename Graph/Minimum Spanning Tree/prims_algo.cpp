#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);



int main() {
    file();

    /*
        Problem Description:
        Given a weighted, undirected, and connected graph of V vertices and E edges. 
        The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
        (It may be asked to find the MST as well, where in the MST the edge-informations will be stored.)

        Input:
        The first line of input contains the number of nodes and edges n, m.
        The next m lines contain the edge ends followed by the weight.

        Complexity analysis:
        TC: O(ElogE)
        SC: O(E) + O(V)

    */

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<pair<int, int>> mst;
    int mstSum = 0;

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<int> vis(n, 0);

    pq.push({0, 0, -1});

    while (!pq.empty()) {
        auto edge = pq.top();
        pq.pop();

        if (vis[edge[1]]) continue;

        vis[edge[1]] = 1;

        if (edge[2] != -1) {
            mst.push_back({edge[1], edge[2]});
            mstSum += edge[0];   
        }

        for (auto p : adj[edge[1]]) {
            if (!vis[p.first]) {
                pq.push({p.second, p.first, edge[1]});
            }
        }
    }

    cout << "Sum of mst weights: " << mstSum << endl;
    cout << "MST edges:" << endl;
    for (auto p : mst) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}