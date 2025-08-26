#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e18

int V, E, s, e;
vector<pair<int, int>> graph[50];
vector<int> dist(50, INF), income(50, 0), visited(50, 0);
queue<int> cycle;
bool minusCycle = false, infinite = false;

int bellman_ford(int s, int e) {
    dist[s] = -income[s];
    for (int i = 1; i <= V; i++)
        for (int j = 0; j < V; j++)
            for (auto [next, d] : graph[j]) {
                if (dist[j] != INF && dist[next] > dist[j] + d - income[next]) {
                    dist[next] = dist[j] + d - income[next];
                    if (i == V) {
                        minusCycle = true;
                        cycle.push(next);
                    }
                }
            }
    return dist[e];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> V >> s >> e >> E;
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    for (int i = 0; i < V; i++)
        cin >> income[i];
    bellman_ford(s, e);
    if (minusCycle) {
        while (!cycle.empty()) {
            int curr = cycle.front();
            cycle.pop();
            visited[curr] = 1;
            for (auto [next, d] : graph[curr])
                if (!visited[next])
                    cycle.push(next);
        }
        if (visited[e])
            infinite = true;
    }
    if (dist[e] == INF)
        cout << "gg";
    else if (infinite)
        cout << "Gee";
    else
        cout << -dist[e];
}