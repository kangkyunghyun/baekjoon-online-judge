#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int p[6];
  for (int i = 1; i <= 5; i++)
    cin >> p[i];
  vector<vector<int>> t(6);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    t[x].push_back(y);
  }
  for (int i = 1; i <= 5; i++)
    sort(t[i].begin(), t[i].end());
  int ans = 0;
  int cnt = 0;
  for (int i = 1; i <= 5; i++) {
    cnt++;
    for (int j = 0; j < p[i]; j++) {
      if (j == 0) {
        ans += t[i][j];
        if (cnt != 1) {
          ans += 60;
        }
      } else {
        ans += 2 * t[i][j] - t[i][j - 1];
      }
    }
  }
  cout << ans;
  return 0;
}