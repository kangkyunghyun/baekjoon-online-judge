// 1504: 특정한 최단 경로
//
// - 문제
// 방향성이 없는 그래프가 주어진다. 세준이는 1번 정점에서 N번 정점으로 최단 거리로 이동하려고 한다. 또한 세준이는 두 가지 조건을 만족하면서 이동하는 특정한 최단 경로를 구하고 싶은데, 그것은 바로 임의로 주어진 두 정점은 반드시 통과해야 한다는 것이다.
// 세준이는 한번 이동했던 정점은 물론, 한번 이동했던 간선도 다시 이동할 수 있다. 하지만 반드시 최단 경로로 이동해야 한다는 사실에 주의하라. 1번 정점에서 N번 정점으로 이동할 때, 주어진 두 정점을 반드시 거치면서 최단 경로로 이동하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 정점의 개수 N과 간선의 개수 E가 주어진다. (2 ≤ N ≤ 800, 0 ≤ E ≤ 200,000) 둘째 줄부터 E개의 줄에 걸쳐서 세 개의 정수 a, b, c가 주어지는데, a번 정점에서 b번 정점까지 양방향 길이 존재하며, 그 거리가 c라는 뜻이다. (1 ≤ c ≤ 1,000) 다음 줄에는 반드시 거쳐야 하는 두 개의 서로 다른 정점 번호 v1과 v2가 주어진다. (v1 ≠ v2, v1 ≠ N, v2 ≠ 1) 임의의 두 정점 u와 v사이에는 간선이 최대 1개 존재한다.
//
// - 출력
// 첫째 줄에 두 개의 정점을 지나는 최단 경로의 길이를 출력한다. 그러한 경로가 없을 때에는 -1을 출력한다.

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
  init();               // 배열 초기화
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
  int ans;
  if (dijkstra(1, v1) == INF || dijkstra(v1, v2) == INF || dijkstra(v2, N) == INF || dijkstra(1, v2) == INF || dijkstra(v2, v1) == INF || dijkstra(v1, N) == INF) {
    ans = -1;
  } else {
    int t1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
    int t2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);
    ans = min(t1, t2);
  }
  cout << ans << '\n';
  return 0;
}