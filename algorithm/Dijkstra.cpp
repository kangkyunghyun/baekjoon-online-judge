// O((E+V)logV)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9
#define pii pair<int, int>

int V, E, K;
int dist[20001];
vector<pii> graph[20001];

int dijkstra(int s, int e) {
    fill(dist, dist + V, INF);
    priority_queue<pii> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if (dist[curr] < cost)
            continue;
        for (pii p : graph[curr]) {
            int next = p.first, d = cost + p.second;
            if (dist[next] > d) {
                dist[next] = d;
                pq.push({-d, next});
            }
        }
    }
    return dist[e];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> V >> E >> K;
    while (E--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    for (int i = 1; i <= V; i++) {
        int ans = dijkstra(K, i);
        if (ans == INF)
            cout << "INF\n";
        else
            cout << ans << '\n';
    }
    return 0;
}