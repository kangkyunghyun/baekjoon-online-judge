#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647

int N, M;
vector<pair<int, int>> graph[50001];
vector<int> dist(50001, INF), visited(50001, 0);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int dijkstra(int s, int e) {
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  while (M--) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }
  cout << dijkstra(1, N);
  return 0;
}