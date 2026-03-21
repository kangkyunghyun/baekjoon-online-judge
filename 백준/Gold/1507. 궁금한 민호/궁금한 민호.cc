#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, ans = 0, dist[21][21], check[21][21];
  cin >> N;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      cin >> dist[i][j];
      check[i][j] = 1;
    }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) {
        if (k == i || i == j || j == k)
          continue;
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          cout << "-1\n";
          return 0;
        } else if (dist[i][j] == dist[i][k] + dist[k][j]) {
          check[i][j] = 0;
        }
      }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (check[i][j])
        ans += dist[i][j];
  cout << ans / 2 << '\n';
  return 0;
}