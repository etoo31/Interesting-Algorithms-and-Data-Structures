#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool>visted;
void dfs(int node)
{
    visted[node] = 1;
    for (auto x : adj[node])
    {
        if (!visted[x])
               dfs(x);
    }
}
int main() {
    int n = 5;
    visted = vector<bool>(6 , 0);
    adj = vector<vector<int>>(6);
    int m = 4;
    while (m--)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 1 ; i < 6; i++)
        cout << visted[i] << " ";
    return 0;
}
