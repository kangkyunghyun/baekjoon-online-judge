// 1238: 파티
//
// - 문제
// N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.
// 어느 날 이 N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다. 이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.
// 각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.
// 이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다. N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.
//
// - 입력
// 첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 10,000), X가 공백으로 구분되어 입력된다. 두 번째 줄부터 M+1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 Ti가 들어온다. 시작점과 끝점이 같은 도로는 없으며, 시작점과 한 도시 A에서 다른 도시 B로 가는 도로의 개수는 최대 1개이다.
// 모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.
//
// - 출력
// 첫 번째 줄에 N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, X, ans = 0;
  cin >> N >> M >> X;

  // 간선
  vector<pair<int, int>> graph[10001]; // [정점][다음 정점, 거리]
  while (M--) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  // 다익스트라
  for (int i = 1; i <= N; i++) {
    vector<int> dist(10001, INT_MAX), visited(10001, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // X까지 가는 최단거리
    dist[i] = 0;          // 시작점 거리 0
    pq.push({0, i});      // 시작점만 pq에 추가
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

    int sum = dist[X];

    // 배열 초기화
    for (int i = 1; i <= N; i++) {
      visited[i] = 0;
      dist[i] = INT_MAX;
    }

    // X에서 돌아가는 최단거리
    dist[X] = 0;          // 시작점 거리 0
    pq.push({0, X});      // 시작점만 pq에 추가
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

    sum += dist[i];
    ans = max(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}