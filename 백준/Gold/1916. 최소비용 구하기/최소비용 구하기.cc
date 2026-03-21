#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, s, e;
  cin >> N >> M;

  // 간선
  vector<pair<int, int>> graph[1001]; // [정점][다음 정점, 거리]
  while (M--) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  cin >> s >> e;

  vector<int> dist(1001, INF), visited(1001, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
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
  cout << dist[e] << '\n';
  return 0;
}