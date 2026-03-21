#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, dist[101][101], m = 1e9, ans = 1;
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      dist[i][j] = i == j ? 0 : INF;
  while (M--) {
    int a, b;
    cin >> a >> b;
    dist[a][b] = 1;
    dist[b][a] = 1;
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= N; j++)
      sum += dist[i][j];
    if (m > sum) {
      m = sum;
      ans = i;
    }
  }
  cout << ans << '\n';
  return 0;
}