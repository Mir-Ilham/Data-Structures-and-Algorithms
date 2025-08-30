#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

void shortestDistance(vector<vector<pair<int, int>>> &adj, int n, int source) {
    vector<int> dist(n, 1e9);
    dist[source] = 0;

    set<pair<int, int>> st;
    st.insert({0, source});

    while (st.size()) {
        auto p = *st.begin();
        st.erase(st.begin());
        int du = p.first, u = p.second;

        for (auto q : adj[u]) {
            int v = q.first, w = q.second;
            if (du + w < dist[v]) {
                dist[v] = du + w;
                st.insert({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "0 to " << i << " distance: " << dist[i] << endl;
    }
}

void shortestPath(vector<vector<pair<int, int>>> &adj, int n, int source, int destination) {
    vector<int> dist(n, 1e9);
    vector<int> prev(n, -1);
    dist[source] = 0;

    set<pair<int, int>> st;
    st.insert({0, source});

    while (st.size()) {
        auto p = *st.begin();
        st.erase(st.begin());
        int du = p.first, u = p.second;

        for (auto q : adj[u]) {
            int v = q.first, w = q.second;
            if (du + w < dist[v]) {
                prev[v] = u;
                dist[v] = du + w;
                st.insert({dist[v], v});
            }
        }
    }

    if (dist[destination] == 1e9) {
        cout << -1 << endl;
        return;
    }

    vector<int> path;
    int temp = destination;
    while (temp != -1) {
        path.push_back(temp);
        temp = prev[temp];
    }

    cout << "Shortest path from " << source << " to " << destination << " is: ";
    
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
}

int main() {
    file();

    /*
        Problem Description:
        Given a weighted undirected graph find:
        1. the shortest distance to all nodes in the graph from a source node.
        2. the shortest path from a source node to any other node.

        Input:
        The first line of input contains the value of the total number of nodes and edges n, m.
        The next m lines contain the values of the two nodes in an edge followed by its weight.

        Complexity analysis:
        TC: O(ElogV)
        SC: O(V) + O(V^2)

    */
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    shortestDistance(adj, n, 0);
    shortestPath(adj, n, 0, 4);

    return 0;
}