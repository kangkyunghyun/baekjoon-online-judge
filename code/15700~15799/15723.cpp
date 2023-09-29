#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, dist[26][26];
  cin >> n;
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++)
      dist[i][j] = i == j ? 0 : INF;
  while (n--) {
    char x, y;
    string s;
    cin >> x >> s >> y;
    dist[x - 'a'][y - 'a'] = 1;
  }
  for (int k = 0; k < 26; k++)
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  cin >> m;
  while (m--) {
    char x, y;
    string s;
    cin >> x >> s >> y;
    cout << (dist[x - 'a'][y - 'a'] == INF ? "F\n" : "T\n");
  }
  return 0;
}