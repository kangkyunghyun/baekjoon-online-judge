#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, s, e;
  cin >> N >> M;
  vector<pair<int, int>> graph[1001];
  while (M--) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  cin >> s >> e;
  vector<int> dist(1001, INF), visited(1001, 0), prev(1001, -1);
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
        prev[next] = curr;
        pq.push({dist[next], next});
      }
    }
  }
  cout << dist[e] << '\n';
  int tmp = e;
  vector<int> ans;
  while (tmp > 0) {
    ans.push_back(tmp);
    tmp = prev[tmp];
  }
  cout << ans.size() << '\n';
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}