#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, dist[51][51];
  cin >> N;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      dist[i][j] = i == j ? 0 : INF;
  while (1) {
    int a, b;
    cin >> a >> b;
    if (a == -1 && b == -1)
      break;
    dist[a][b] = 1;
    dist[b][a] = 1;
  }
  for (int k = 1; k <= N; k++)
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= N; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  vector<int> member(N + 1), ans;
  int M = INF;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int tmp = *max_element(dist[i] + 1, dist[i] + N + 1);
      if (tmp == INF)
        continue;
      if (tmp < M)
        M = tmp;
      member[i] = tmp;
    }
  }
  cout << M << ' ';
  int cnt = 0;
  for (int i = 1; i <= N; i++)
    if (member[i] == M) {
      cnt++;
      ans.push_back(i);
    }
  cout << cnt << '\n';
  for (int i : ans)
    cout << i << ' ';
  cout << '\n';
  return 0;
}