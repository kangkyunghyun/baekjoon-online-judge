#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, S, E, ans = 0;
    vector<pair<int, int>> edge[10001], reverseEdge[10001];
    vector<int> inDegree(10001, 0), dist(10001, 0), visited(10001, 0);
    cin >> N >> M;
    while (M--) {
        int u, v, c;
        cin >> u >> v >> c;
        inDegree[v]++;
        edge[u].push_back({v, c});
        reverseEdge[v].push_back({u, c});
    }
    cin >> S >> E;
    queue<int> q;
    q.push(S);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto [next, cost] : edge[curr]) {
            dist[next] = max(dist[next], dist[curr] + cost);
            if (--inDegree[next] == 0)
                q.push(next);
        }
    }
    q.push(E);
    visited[E] = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto [next, cost] : reverseEdge[curr])
            if (dist[next] + cost == dist[curr]) {
                ans++;
                if (!visited[next]) {
                    visited[next] = 1;
                    q.push(next);
                }
            }
    }
    cout << dist[E] << '\n'
         << ans;
}