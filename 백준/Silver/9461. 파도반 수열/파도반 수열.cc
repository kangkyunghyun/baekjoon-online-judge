#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> dp(n, 0);
    dp[0] = 1, dp[1] = 1, dp[2] = 1;
    for (int i = 3; i < n; i++)
      dp[i] = dp[i - 2] + dp[i - 3];
    cout << dp[n - 1] << '\n';
  }
  return 0;
}