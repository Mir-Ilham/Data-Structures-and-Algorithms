#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

class DisjointSet {
    vector<int> size, parent;

public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv]; 
        }
    }
};

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


    */

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, u, v});
    }

    sort(edges.begin(), edges.end());

    DisjointSet ds(n);
    vector<pair<int, int>> mst;
    int mstSum = 0;

    for (auto &edge : edges) {
        if (ds.findParent(edge[1]) == ds.findParent(edge[2]))
            continue;
        
        mstSum += edge[0];
        mst.push_back({edge[1], edge[2]});
        ds.unionBySize(edge[1], edge[2]);
    }

    cout << "Sum of mst weights: " << mstSum << endl;
    cout << "MST edges:" << endl;
    for (auto p : mst) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}