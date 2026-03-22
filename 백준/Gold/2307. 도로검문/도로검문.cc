#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int N, M;
vector<pair<int, int>> graph[1001];
vector<int> dist(1001, INF), visited(1001, 0), bef(1001, -1);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void init() {
  for (int i = 1; i <= N; i++) {
    visited[i] = 0;
    dist[i] = INF;
  }
}

int dijkstra(int s, int e) {
  init();
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
      int next = p.first;
      int d = p.second;
      if (dist[next] > dist[curr] + d) {
        dist[next] = dist[curr] + d;
        bef[next] = curr;
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
    int a, b, t;
    cin >> a >> b >> t;
    graph[a].push_back({b, t});
    graph[b].push_back({a, t});
  }
  int m = dijkstra(1, N), ans = -1;
  int tmp = N;
  vector<int> way;
  while (tmp > 0) {
    way.push_back(tmp);
    tmp = bef[tmp];
  }
  for (int i = 0; i < way.size() - 1; i++) {
    int a = way[i], b = way[i + 1];
    int a_idx, b_idx, a_cost, b_cost;
    for (int j = 0; j < graph[a].size(); j++)
      if (graph[a][j].first == b) {
        a_idx = j;
        a_cost = graph[a][j].second;
        graph[a][j].second = INF;
        break;
      }
    for (int j = 0; j < graph[b].size(); j++)
      if (graph[b][j].first == a) {
        b_idx = j;
        b_cost = graph[b][j].second;
        graph[b][j].second = INF;
        break;
      }
    int time = dijkstra(1, N);
    if (time == INF) {
      ans = -1;
      break;
    }
    int gap = time - m;
    ans = max(ans, gap);
    graph[a][a_idx].second = a_cost;
    graph[b][b_idx].second = b_cost;
  }
  cout << ans << '\n';
  return 0;
}