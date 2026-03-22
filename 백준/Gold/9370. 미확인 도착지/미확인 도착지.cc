#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, m, t, s, g, h;
vector<pair<int, int>> graph[2001];
vector<int> dist(2001, INF), visited(2001, 0);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void init() {
  for (int i = 1; i <= n; i++) {
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
      int next = p.first, d = p.second;
      if (dist[next] > dist[curr] + d) {
        dist[next] = dist[curr] + d;
        pq.push({dist[next], next});
      }
    }
  }
  return dist[e];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int len;
    for (int i = 1; i <= n; i++)
      graph[i].clear();
    cin >> n >> m >> t >> s >> g >> h;
    while (m--) {
      int a, b, d;
      cin >> a >> b >> d;
      if ((a == g && b == h) || (a == h && b == g))
        len = d;
      graph[a].push_back({b, d});
      graph[b].push_back({a, d});
    }
    int GH = dijkstra(g, h), SG = dijkstra(s, g), SH = dijkstra(s, h);
    vector<int> ans;
    for (int i = 0; i < t; i++) {
      int x;
      cin >> x;
      int minDist = dijkstra(s, x);
      int GD = dijkstra(g, x), HD = dijkstra(h, x);
      if (SG + GH + HD == minDist || SH + GH + GD == minDist)
        ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    for (int i : ans)
      cout << i << ' ';
    cout << '\n';
  }
  return 0;
}