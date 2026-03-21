#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9
#define pii pair<int, int>

int n, m, s, e;
int dist[100001];
vector<pii> graph[100001];

int dijkstra(int s, int e) {
    fill(dist, dist + n, 0);
    priority_queue<pii> pq;
    dist[s] = INF;
    pq.push({INF, s});
    while (!pq.empty()) {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if (dist[curr] > cost)
            continue;
        for (pii p : graph[curr]) {
            int next = p.first, d = min(cost, p.second);
            if (dist[next] < d) {
                dist[next] = d;
                pq.push({d, next});
            }
        }
    }
    return dist[e];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s >> e;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    cout << dijkstra(s, e);
}