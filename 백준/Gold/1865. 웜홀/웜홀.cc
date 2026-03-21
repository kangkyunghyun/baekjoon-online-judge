#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int T, N, M, W;
vector<pair<int, int>> graph[501];
vector<int> dist(501, INF);
bool minusCycle = false;

void bellman_ford(int s) {
  dist[s] = 0;
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
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  while (T--) {
    cin >> N >> M >> W;
    minusCycle = false;
    for (int i = 1; i <= N; i++) {
      dist[i] = INF;
      graph[i].clear();
    }
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
    bellman_ford(1);
    cout << (minusCycle || dist[1] < 0 ? "YES\n" : "NO\n");
  }
  return 0;
}