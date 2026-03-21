#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> dp(n + 1, 0), v(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  dp[1] = v[1];
  dp[2] = v[1] + v[2];
  dp[3] = max(v[1], v[2]) + v[3];
  for (int i = 4; i <= n; i++)
    dp[i] = max(dp[i - 3] + v[i - 1], dp[i - 2]) + v[i];
  cout << dp[n] << '\n';
  return 0;
}