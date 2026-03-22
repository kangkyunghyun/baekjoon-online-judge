#include <bits/stdc++.h>
using namespace std;
#define INF 1e5

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, ans = 0, dist[100][100];
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      dist[i][j] = i == j ? 0 : INF;
  for (int i = 1; i <= M; i++) {
    int a, b;
    cin >> a >> b;
    dist[b][a] = 1;
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  for (int i = 1; i <= N; i++) {
    int small = 0, big = 0;
    for (int j = 1; j <= N; j++) {
      if (dist[i][j] == 0)
        continue;
      if (dist[i][j] != INF)
        small++;
      else if (dist[j][i] != INF)
        big++;
    }
    if (small > N / 2 || big > N / 2)
      ans++;
  }
  cout << ans << '\n';
  return 0;
}