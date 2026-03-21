#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  vector<pair<int, int>> graph[1001];
  vector<int> dist(1001, INF), visited(1001, 0), prev(1001, -1);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  cin >> N >> M;
  while (M--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }
  dist[1] = 0;
  pq.push({0, 1});
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
  int cnt = 0;
  for (int i = 1; i <= N; i++)
    if (prev[i] != -1)
      cnt++;
  cout << cnt << '\n';
  for (int i = 2; i <= N; i++)
    cout << i << ' ' << prev[i] << '\n';
  return 0;
}