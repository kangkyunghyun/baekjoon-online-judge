#include <bits/stdc++.h>
using namespace std;
#define INF 1e18

int V, E;
vector<pair<int, int>> graph[501];
vector<long long> dist(501, INF);
bool minusCycle = false;

int bellman_ford(int s, int e) {
    dist[s] = 0;
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            for (auto &p : graph[j]) {
                int next = p.first, d = p.second;
                if (dist[j] != INF && dist[next] > dist[j] + d) {
                    dist[next] = dist[j] + d;
                    if (i == V)
                        minusCycle = true;
                }
            }
    return dist[e];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
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
// O(VE)