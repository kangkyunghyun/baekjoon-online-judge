#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647

int N, E, v1, v2;
vector<pair<int, int>> graph[801]; // [정점][다음 정점, 거리]
vector<int> dist(801, INF), visited(801, 0);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void init() {
  for (int i = 1; i <= N; i++) {
    visited[i] = 0;
    dist[i] = INF;
  }
}

int dijkstra(int s, int e) {
  init();
  dist[s] = 0;          // 시작점 거리 0
  pq.push({0, s});      // 시작점만 pq에 추가
  while (!pq.empty()) { // pq가 비면 종료
    int curr;
    do {
      curr = pq.top().second;
      pq.pop();
    } while (!pq.empty() && visited[curr]); // curr이 방문한 정점이면 무시
    // 더 이상 방문할 수 있는 정점이 없으면 종료
    if (visited[curr])
      break;
    visited[curr] = 1; // 방문처리
    for (auto &p : graph[curr]) {
      int next = p.first, d = p.second;
      // 거리가 갱신될 경우 pq에 추가
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
  cin >> N >> E;

  // 간선
  while (E--) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  cin >> v1 >> v2;

  // 다익스트라
  if (dijkstra(1, v1) == INF || dijkstra(v1, v2) == INF || dijkstra(v2, N) == INF) {
    cout << -1;
    return 0;
  }
  if (dijkstra(1, v2) == INF || dijkstra(v2, v1) == INF || dijkstra(v1, N) == INF) {
    cout << -1;
    return 0;
  }
  int t1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
  int t2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);
  int ans = min(t1, t2);
  cout << ans << '\n';
  return 0;
}