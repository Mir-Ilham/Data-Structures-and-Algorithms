#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

class DisjointSet {
    vector<int> rank, size, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
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

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
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
        Implement the Disjoint Set Union data structure.
        Given two nodes of a graph determine if they belong to the same component or not.

        Input:
        Total number of nodes and graph edges.

        Complexity analysis:
        TC: O(4 * Alpha) ~ O(1)
    */
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findParent(3) == ds.findParent(7))
        cout << "Same" << endl;
    else
        cout << "Not same" << endl;
    
    ds.unionBySize(3, 7);

    if (ds.findParent(3) == ds.findParent(7))
        cout << "Same" << endl;
    else
        cout << "Not same" << endl;
    
    return 0;
}