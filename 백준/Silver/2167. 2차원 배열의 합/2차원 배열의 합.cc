#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, k;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> v[i][j];
  cin >> k;
  while (k--) {
    int i, j, x, y, sum = 0, brk = 0;
    cin >> i >> j >> x >> y;
    for (int a = i - 1; a <= x - 1; a++)
      for (int b = j - 1; b <= y - 1; b++)
        sum += v[a][b];
    cout << sum << '\n';
  }
  return 0;
}