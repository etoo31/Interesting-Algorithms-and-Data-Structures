#include <bits/stdc++.h>
using namespace std;
#define cost .first
#define form .second.first
#define to   .second.second

int main() {
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n = 5;
    vector<vector<long long>>dist(n , vector<long long>(n , 1e18));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    int m = 6;
    while (m--)
    {
        long long u , v , c;
        cin >> u >> v >> c;
        dist[u][v] = min(c , dist[u][v]);
        dist[v][u] = min(c , dist[v][u]);
    }
    //floyd
    for (int k = 0 ; k < n; k++)
        for (int i = 0 ; i < n; i++)
            for (int j = 0 ;j < n; j++)
                dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << dist[i][j] << " \n"[j == n-1];
    }

    return 0;
}
