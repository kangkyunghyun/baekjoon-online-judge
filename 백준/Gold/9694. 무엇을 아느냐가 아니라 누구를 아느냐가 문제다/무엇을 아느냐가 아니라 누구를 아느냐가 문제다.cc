#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int T, N, M;
vector<pair<int, int>> graph[20];
vector<int> dist(20, INF), visited(20, 0), bef(20, -1);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void init() {
  for (int i = 0; i < M; i++) {
    graph[i].clear();
    visited[i] = 0;
    bef[i] = -1;
    dist[i] = INF;
  }
}

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
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> N >> M;
    init();
    while (N--) {
      int x, y, z;
      cin >> x >> y >> z;
      graph[x].push_back({y, z});
      graph[y].push_back({x, z});
    }
    cout << "Case #" << i << ": ";
    if (dijkstra(0, M - 1) == INF) {
      cout << -1;
    } else {
      vector<int> way;
      int tmp = M - 1;
      while (tmp >= 0) {
        way.push_back(tmp);
        tmp = bef[tmp];
      }
      for (int i = way.size() - 1; i >= 0; i--)
        cout << way[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}