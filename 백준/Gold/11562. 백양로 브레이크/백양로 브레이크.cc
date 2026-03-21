#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, K, ans, dist[251][251];
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      dist[i][j] = i == j ? 0 : INF;
  for (int i = 1; i <= M; i++) {
    int u, v, b;
    cin >> u >> v >> b;
    dist[u][v] = 0;
    dist[v][u] = b ? 0 : 1;
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  cin >> K;
  while (K--) {
    int s, e;
    cin >> s >> e;
    cout << dist[s][e] << '\n';
  }
  return 0;
}