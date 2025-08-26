// Bellman Ford O(VE)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

int V, E;
vector<pair<int, int>> graph[501];
vector<int> dist(501, INF);
bool minusCycle = false;

int bellman_ford(int s, int e) {
    dist[s] = 0;
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            for (auto [next, d] : graph[j]) {
                if (dist[j] != INF && dist[next] > dist[j] + d) {
                    dist[next] = dist[j] + d;
                    if (i == V)
                        minusCycle = true;
                }
            }
    return dist[e];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> V >> E;

    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    bellman_ford(1, V);

    if (minusCycle)
        cout << "-1\n";
    else
        for (int i = 1; i <= V; i++)
            cout << (dist[i] != INF ? dist[i] : -1) << '\n';

    return 0;
}