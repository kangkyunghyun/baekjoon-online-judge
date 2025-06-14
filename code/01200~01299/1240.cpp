#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9
#define pii pair<int, int>

int N, M;
int dist[1001];
vector<pii> graph[1001];

int dijkstra(int s, int e) {
    fill(dist, dist + N + 1, INF);
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
    cin >> N >> M;
    for (int i = 1; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    while (M--) {
        int u, v;
        cin >> u >> v;
        cout << dijkstra(u, v) << '\n';
    }
}