#include <bits/stdc++.h>
using namespace std;
#define INF 1e18

int N, M;
vector<pair<int, int>> graph[501];
vector<long long> dist(501, INF);
bool minusCycle = false;

void bellman_ford(int s) {
  dist[s] = 0;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      for (auto &p : graph[j]) {
        int next = p.first, d = p.second;
        if (dist[j] != INF && dist[next] > dist[j] + d) {
          dist[next] = dist[j] + d;
          if (i == N)
            minusCycle = true;
        }
      }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  while (M--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }
  bellman_ford(1);
  if (minusCycle)
    cout << "-1\n";
  else
    for (int i = 2; i <= N; i++)
      cout << (dist[i] != INF ? dist[i] : -1) << '\n';
  return 0;
}