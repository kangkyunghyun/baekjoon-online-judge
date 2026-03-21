#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> dp(n + 1, 0);
  dp[0] = 1, dp[2] = 3;
  for (int i = 4; i <= n; i += 2) {
    dp[i] = dp[2] * dp[i - 2];
    for (int j = 4; j <= i; j += 2)
      dp[i] += 2 * dp[i - j];
  }
  cout << dp[n];
  return 0;
}