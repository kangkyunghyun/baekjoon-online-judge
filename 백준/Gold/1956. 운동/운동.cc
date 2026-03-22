#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int V, E, dist[401][401];
  cin >> V >> E;
  for (int i = 1; i <= V; i++)
    for (int j = 1; j <= V; j++)
      dist[i][j] = i == j ? 0 : INF;
  while (E--) {
    int a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = c;
  }
  for (int k = 1; k <= V; k++)
    for (int i = 1; i <= V; i++)
      for (int j = 1; j <= V; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  int ans = INF;
  for (int i = 1; i <= V; i++)
    for (int j = 1; j <= V; j++)
      if (dist[i][j])
        ans = min(ans, dist[i][j] + dist[j][i]);
  cout << (ans != INF ? ans : -1) << '\n';
  return 0;
}