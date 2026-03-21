#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int dp[1001][3] = {0};
  for (int i = 1; i <= n; i++) {
    int r, g, b;
    cin >> r >> g >> b;
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r;
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g;
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b;
  }
  cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
  return 0;
}