#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, s, t;
  cin >> n >> m;
  vector<pair<int, int>> graph[20001];
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  cin >> s >> t;
  vector<int> dist(20001, INF), visited(20001, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
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
  cout << dist[t] << '\n';
  return 0;
}