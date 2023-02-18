// 1916: 최소비용 구하기
//
// - 문제
// N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다. 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라. 도시의 번호는 1부터 N까지이다.
//
// - 입력
// 첫째 줄에 도시의 개수 N(1 ≤ N ≤ 1,000)이 주어지고 둘째 줄에는 버스의 개수 M(1 ≤ M ≤ 100,000)이 주어진다. 그리고 셋째 줄부터 M+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다. 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.
// 그리고 M+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다. 출발점에서 도착점을 갈 수 있는 경우만 입력으로 주어진다.
//
// - 출력
// 첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.

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