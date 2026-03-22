#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, K, dist[401][401], S;
  cin >> N >> K;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      dist[i][j] = i == j ? 1 : INF;
  while (K--) {
    int a, b;
    cin >> a >> b;
    dist[a][b] = 1;
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  cin >> S;
  while (S--) {
    int a, b;
    cin >> a >> b;
    if (dist[a][b] != INF)
      cout << -1;
    else if (dist[b][a] != INF)
      cout << 1;
    else
      cout << 0;
    cout << '\n';
  }
  return 0;
}