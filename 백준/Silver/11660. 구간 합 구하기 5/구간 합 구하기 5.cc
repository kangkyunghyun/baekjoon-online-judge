#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      sum[i][j] = sum[i][j - 1] + x;
    }
  while (m--) {
    int x1, y1, x2, y2, ans = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i <= x2; i++)
      ans += sum[i][y2] - sum[i][y1 - 1];
    cout << ans << '\n';
  }
  return 0;
}