#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, b, ans = INT_MAX, ans_h = 0;
  cin >> n >> m >> b;
  vector<vector<int>> v(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> v[i][j];

  for (int h = 0; h <= 256; h++) {
    int remove = 0, put = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (v[i][j] > h)
          remove += v[i][j] - h;
        else if (v[i][j] < h)
          put += h - v[i][j];
    if (remove + b >= put) {
      int time = remove * 2 + put;
      if (time <= ans) {
        ans = time;
        ans_h = h;
      }
    }
  }
  cout << ans << ' ' << ans_h;
  return 0;
}