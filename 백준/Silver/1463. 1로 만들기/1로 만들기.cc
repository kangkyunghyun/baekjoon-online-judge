#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[1] = 0;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    if (!(i % 3))
      dp[i] = min(dp[i], dp[i / 3] + 1);
    if (!(i % 2))
      dp[i] = min(dp[i], dp[i / 2] + 1);
  }
  cout << dp[n];
  return 0;
}