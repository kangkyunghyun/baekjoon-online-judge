// 5719: 거의 최단 경로
//
// - 문제
// 요즘 많은 자동차에서는 GPS 네비게이션 장비가 설치되어 있다. 네비게이션은 사용자가 입력한 출발점과 도착점 사이의 최단 경로를 검색해 준다. 하지만, 교통 상황을 고려하지 않고 최단 경로를 검색하는 경우에는 극심한 교통 정체를 경험할 수 있다.
// 상근이는 오직 자기 자신만 사용 가능한 네비게이션을 만들고 있다. 이 네비게이션은 절대로 최단 경로를 찾아주지 않는다. 항상 거의 최단 경로를 찾아준다.
// 거의 최단 경로란 최단 경로에 포함되지 않는 도로로만 이루어진 경로 중 가장 짧은 것을 말한다.
// 예를 들어, 도로 지도가 아래와 같을 때를 생각해보자. 원은 장소를 의미하고, 선은 단방향 도로를 나타낸다. 시작점은 S, 도착점은 D로 표시되어 있다. 굵은 선은 최단 경로를 나타낸다. (아래 그림에 최단 경로는 두 개가 있다)거의 최단 경로는 점선으로 표시된 경로이다. 이 경로는 최단 경로에 포함되지 않은 도로로 이루어진 경로 중 가장 짧은 경로이다. 거의 최단 경로는 여러 개 존재할 수도 있다. 예를 들어, 아래 그림의 길이가 3인 도로의 길이가 1이라면, 거의 최단 경로는 두 개가 된다. 또, 거의 최단 경로가 없는 경우도 있다.
//
// - 입력
// 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 장소의 수 N (2 ≤ N ≤ 500)과 도로의 수 M (1 ≤ M ≤ 104)가 주어진다. 장소는 0부터 N-1번까지 번호가 매겨져 있다. 둘째 줄에는 시작점 S와 도착점 D가 주어진다. (S ≠ D; 0 ≤ S, D < N) 다음 M개 줄에는 도로의 정보 U, V, P가 주어진다. (U ≠ V ; 0 ≤ U, V < N; 1 ≤ P ≤ 103) 이 뜻은 U에서 V로 가는 도로의 길이가 P라는 뜻이다. U에서 V로 가는 도로는 최대 한 개이다. 또, U에서 V로 가는 도로와 V에서 U로 가는 도로는 다른 도로이다.
// 입력의 마지막 줄에는 0이 두 개 주어진다.
//
// - 출력
// 각 테스트 케이스에 대해서, 거의 최단 경로의 길이를 출력한다. 만약, 거의 최단 경로가 없는 경우에는 -1을 출력한다.

// Sol 1 - 방문 처리
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

// Sol 2 - 조건 추가
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
  q.push(D);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int i = 0; i < reverse_graph[curr].size(); i++) {
      int next = reverse_graph[curr][i].first;
      int cost = reverse_graph[curr][i].second;
      if (dist[curr] - dist[next] == cost)
        for (int j = 0; j < graph[next].size(); j++)
          if (graph[next][j].first == curr && graph[next][j].second != INF) {
            graph[next][j].second = INF;
            q.push(next);
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