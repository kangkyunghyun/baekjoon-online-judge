#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, dist[101][101];
  cin >> N;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      cin >> dist[i][j];
      if (dist[i][j] == 0)
        dist[i][j] = INF;
    }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++)
      cout << (dist[i][j] == INF ? 0 : 1) << ' ';
    cout << '\n';
  }
  return 0;
}