#include <bits/stdc++.h>
using namespace std;

#define INF 10000000001

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  cin >> N >> M;
  vector<int> v(N);
  for (int i = 0; i < N; i++)
    cin >> v[i];
  vector<pair<int, int>> graph[100001];
  while (M--) {
    int a, b, t;
    cin >> a >> b >> t;
    if (a != N - 1 && b != N - 1 && (v[a] == 1 || v[b] == 1))
      continue;
    graph[a].push_back({b, t});
    graph[b].push_back({a, t});
  }
  vector<int> visited(100001, 0);
  vector<long long> dist(100001, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  dist[0] = 0;
  pq.push({0, 0});
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
  if (dist[N - 1] == INF)
    cout << "-1\n";
  else
    cout << dist[N - 1] << '\n';
  return 0;
}