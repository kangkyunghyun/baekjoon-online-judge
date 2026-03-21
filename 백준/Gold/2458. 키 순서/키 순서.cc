#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, dist[501][501], cnt = 0;
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      dist[i][j] = INF;
  while (M--) {
    int a, b;
    cin >> a >> b;
    dist[a][b] = 1;
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  for (int i = 1; i <= N; i++) {
    int flag = 1;
    for (int j = 1; j <= N; j++) {
      if (i == j)
        continue;
      if (dist[i][j] == INF && dist[j][i] == INF) {
        flag = 0;
        break;
      }
    }
    if (flag)
      cnt++;
  }
  cout << cnt << '\n';
  return 0;
}