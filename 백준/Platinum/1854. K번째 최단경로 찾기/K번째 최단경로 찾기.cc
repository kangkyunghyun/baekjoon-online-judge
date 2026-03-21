#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int V, E, K;
  vector<pii> graph[1001];
  cin >> V >> E >> K;
  while (E--) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  priority_queue<int> h[1001];
  priority_queue<pii> pq;
  h[1].push(0);
  pq.push({0, 1});
  while (!pq.empty()) {
    int cost = -pq.top().first;
    int curr = pq.top().second;
    pq.pop();
    for (pii p : graph[curr]) {
      int next = p.first, d = cost + p.second;
      if (h[next].size() < K) {
        h[next].push(d);
        pq.push({-d, next});
      } else if (h[next].top() > d) {
        h[next].pop();
        h[next].push(d);
        pq.push({-d, next});
      }
    }
  }
  for (int i = 1; i <= V; i++)
    cout << (h[i].size() < K ? -1 : h[i].top()) << '\n';
  return 0;
}