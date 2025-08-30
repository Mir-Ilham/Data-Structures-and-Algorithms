#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

void topoSort(vector<vector<int>> &adj, int i, stack<int> &st, vector<int> &vis) {
    vis[i] = 1;

    for (int j : adj[i]) {
        if (!vis[j])
            topoSort(adj, j, st, vis);
    }
        
    st.push(i);
}

void dfs(vector<vector<int>> &adj, int i, vector<int> &vis) {
    vis[i] = 1;

    cout << i << " ";
    for (int j : adj[i]) {
        if (!vis[j]) {
            dfs(adj, j, vis);
        }
    }
}

int main() {
    file();

    /*
        Problem Description:
        Given a directed graph, find all the strongly connected components

        Input:
        The first line of input contains the total number of nodes. Each consecutive line
        represents the edges of the i-th node (zero indexed). The lines start with the edge count
        followed by the destination node values.

        Complexity analysis:
        TC - O(V + E)
        SC - O(V + E) + O(V)
    */
    int n;
    cin >> n;

    vector<vector<int>> adj(n), transpose(n);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        while (e--) {
            int v;
            cin >> v;
            adj[i].push_back(v);
        }
    }

    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            topoSort(adj, i, st, vis);
    }        

    for (int i = 0; i < n; i++) {
        vis[i] = 0;
        for (int j : adj[i])
            transpose[j].push_back(i);
    }

    while (!st.empty()) {
        int i = st.top();
        st.pop();
        if (!vis[i]) {
            dfs(transpose, i, vis);
            cout << endl;
        }
    }

    return 0;
}