#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int dp[1000001] = {0, 1}, n;
  cin >> n;
  for (int i = 2; i <= n; i++)
    dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;
  cout << dp[n];
  return 0;
}