#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  ll dist[101][101];
  vector<int> path[101][101];
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (i == j) {
        dist[i][j] = 0;
      } else {
        dist[i][j] = INF;
        path[i][j] = {i, j};
      }
  while (M--) {
    ll a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          vector<int> tmp{path[i][k]};
          tmp.insert(tmp.end(), path[k][j].begin() + 1, path[k][j].end());
          path[i][j] = tmp;
        }
      }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++)
      cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
    cout << '\n';
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (path[i][j].size() == 0 || dist[i][j] == INF)
        cout << "0\n";
      else {
        cout << path[i][j].size() << ' ';
        for (int e : path[i][j])
          cout << e << ' ';
        cout << '\n';
      }
    }
  }
  return 0;
}