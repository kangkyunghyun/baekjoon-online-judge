#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, X, ans = 0;
  cin >> N >> M >> X;
  vector<pair<int, int>> graph[10001];
  while (M--) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  for (int i = 1; i <= N; i++) {
    vector<int> dist(10001, INT_MAX), visited(10001, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[i] = 0;
    pq.push({0, i});
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
    int sum = dist[X];
    for (int i = 1; i <= N; i++) {
      visited[i] = 0;
      dist[i] = INT_MAX;
    }
    dist[X] = 0;
    pq.push({0, X});
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
    sum += dist[i];
    ans = max(ans, sum);
  }
  cout << ans << '\n';
  return 0;
}