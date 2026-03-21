#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, dist[101][101];
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      dist[i][j] = i == j ? 0 : INF;
  for (int i = 1; i <= M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++)
      cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
    cout << '\n';
  }
  return 0;
}