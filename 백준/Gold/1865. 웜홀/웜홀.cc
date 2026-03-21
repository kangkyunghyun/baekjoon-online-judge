#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int N, M, W;
    vector<pair<int, int>> graph[501];
    vector<int> dist(501, INF);
    bool minusCycle = false;
    cin >> N >> M >> W;
    while (M--) {
      int s, e, t;
      cin >> s >> e >> t;
      graph[s].push_back({e, t});
      graph[e].push_back({s, t});
    }
    while (W--) {
      int s, e, t;
      cin >> s >> e >> t;
      graph[s].push_back({e, -t});
    }
    dist[1] = 0;
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        for (auto &p : graph[j]) {
          int next = p.first, d = p.second;
          if (dist[next] > dist[j] + d) {
            dist[next] = dist[j] + d;
            if (i == N)
              minusCycle = true;
          }
        }
    cout << (minusCycle ? "YES\n" : "NO\n");
  }
  return 0;
}