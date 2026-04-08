// Day 67 - Q1: Topological Sort (DFS)
// Topic: Topological Sort, DFS
// Time: O(V+E), Space: O(V)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, int vis[], stack<int>& st, vector<int> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node])
        if (!vis[it]) dfs(it, vis, st, adj);
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    int vis[V + 1] = {0};
    stack<int> st;
    for (int i = 1; i <= V; i++)
        if (!vis[i]) dfs(i, vis, st, adj);
    vector<int> ans;
    while (!st.empty()) { ans.push_back(st.top()); st.pop(); }
    return ans;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V + 1];
    for (int i = 0; i < E; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); // directed
    }
    vector<int> res = topoSort(V, adj);
    cout << "Topological Order: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
