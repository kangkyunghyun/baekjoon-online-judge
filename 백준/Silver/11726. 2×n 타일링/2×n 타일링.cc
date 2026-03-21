#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[1] = 1, dp[2] = 2;
  for (int i = 3; i <= n; i++)
    dp[i] = ((dp[i - 1] % 10007) + (dp[i - 2] % 10007)) % 10007;
  cout << dp[n] % 10007;
  return 0;
}