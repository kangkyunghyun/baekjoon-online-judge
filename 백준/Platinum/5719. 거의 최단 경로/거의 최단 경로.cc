#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int N, M, S, D;
vector<pair<int, int>> graph[500], reverse_graph[500];
vector<int> dist(500, INF), visited(500, 0);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int dijkstra(int s, int e) {
  for (int i = 0; i < N; i++) {
    visited[i] = 0;
    dist[i] = INF;
  }
  dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    int curr;
    do {
      curr = pq.top().second;
      pq.pop();
    } while (!pq.empty() && visited[curr]);
    if (visited[curr])
      break;
    visited[curr] = 1;
    for (auto &p : graph[curr]) {
      int next = p.first, d = p.second;
      if (dist[next] > dist[curr] + d) {
        dist[next] = dist[curr] + d;
        pq.push({dist[next], next});
      }
    }
  }
  return dist[e];
}

void bfs() {
  queue<int> q;
  vector<bool> vst(500, 0);
  q.push(D);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int i = 0; i < reverse_graph[curr].size(); i++) {
      int next = reverse_graph[curr][i].first;
      int cost = reverse_graph[curr][i].second;
      if (dist[curr] - dist[next] == cost)
        for (int j = 0; j < graph[next].size(); j++)
          if (graph[next][j].first == curr) {
            graph[next][j].second = INF;
            if (!vst[next]) {
              vst[next] = 1;
              q.push(next);
            }
            break;
          }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    for (int i = 0; i < N; i++) {
      graph[i].clear();
      reverse_graph[i].clear();
    }
    cin >> N >> M;
    if (!(N + M))
      break;
    cin >> S >> D;
    while (M--) {
      int u, v, w;
      cin >> u >> v >> w;
      graph[u].push_back({v, w});
      reverse_graph[v].push_back({u, w});
    }
    dijkstra(S, D);
    bfs();
    int ans = dijkstra(S, D);
    cout << (ans == INF ? -1 : ans) << '\n';
  }
  return 0;
}