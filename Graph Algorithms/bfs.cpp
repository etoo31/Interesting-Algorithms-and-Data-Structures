#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool>visted;
void bfs(int start)
{
    queue<int>q;
    q.push(start);
    visted[start] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto x : adj[node])
        {
            if (!visted[x])
            {
                visted[x] = 1;
                q.push(x);
            }
        }
    }

}
int main() {
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n = 6;
    adj = vector<vector<int>>(n);
    visted = vector<bool>(n , 0);
    int m = 4;
    while (m--)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    for (int i = 1; i < 6; i++)
        cout << visted[i] << " ";


    return 0;
}
