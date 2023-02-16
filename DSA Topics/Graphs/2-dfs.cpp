#include <bits/stdc++.h>
using namespace std;

// TC->O(N+2*E)
// SC->O(N)
void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans)
{

    vis[node] = 1;
    ans.push_back(node);

    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis, ans);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> ans;
    dfs(0, adj, vis, ans);

    return ans;
}