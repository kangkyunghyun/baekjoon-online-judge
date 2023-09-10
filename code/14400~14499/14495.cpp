#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<long long> dp(117);
  dp[1] = dp[2] = dp[3] = 1;
  for (int i = 4; i <= 116; i++)
    dp[i] = dp[i - 1] + dp[i - 3];
  int n;
  cin >> n;
  cout << dp[n];
  return 0;
}