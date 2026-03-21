#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647

int N, D, C;
vector<pair<int, int>> graph[10001];
vector<int> dist(10001, INF), visited(10001, 0);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void init() {
  for (int i = 1; i <= N; i++) {
    visited[i] = 0;
    dist[i] = INF;
  }
}

void dijkstra(int s) {
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
      int next = p.first, d = p.second;
      if (dist[next] > dist[curr] + d) {
        dist[next] = dist[curr] + d;
        pq.push({dist[next], next});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    cin >> N >> D >> C;
    for (int i = 1; i <= N; i++)
      graph[i].clear();
    for (int i = 0; i < D; i++) {
      int a, b, s;
      cin >> a >> b >> s;
      graph[b].push_back({a, s});
    }
    dijkstra(C);
    int cnt = 0, t = 0;
    for (int i = 1; i <= N; i++)
      if (dist[i] != INF) {
        cnt++;
        t = max(t, dist[i]);
      }
    cout << cnt << ' ' << t << '\n';
  }
  return 0;
}