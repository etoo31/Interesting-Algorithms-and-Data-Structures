#include <bits/stdc++.h>
using namespace std;
#define cost first
#define to  second
vector<vector<pair<long long , int>>>adj;
long long dijkstra(int start ,int e)
{
    vector<long long>dist(6 , 1e18);
    priority_queue<pair<long long , int>>q;
    dist[start] = 0;
    q.push({dist[start] * -1 ,start });
    while (!q.empty())
    {
        int current = q.top().second;
        long long c = q.top().cost;
        c*= -1;
        q.pop();
        if (c != dist[current])continue;
        if (current == e)return dist[e];
        for (auto x : adj[current])
        {
            if (c + x.cost < dist[x.to])
            {
                dist[x.to] = c + x.cost;
                q.push({dist[x.to]*-1  , x.to});
            }
        }
    }
    return -1;
}

int main() {
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n = 6 , m = 6;
    adj = vector<vector<pair<long long , int>>>(n);
    while (m--)
    {
        int u , v , c;
        cin >> u >> v >> c;
        adj[u].push_back({c , v});
        adj[v].push_back({c , u});

    }
    cout << dijkstra(1 , 4) << endl;
    return 0;
}
