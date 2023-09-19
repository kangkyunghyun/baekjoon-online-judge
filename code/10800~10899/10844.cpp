#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  int dp[1001][10] = {0};
  fill(dp[1] + 1, dp[1] + 10, 1);
  for (int i = 2; i <= n; i++)
    for (int j = 0; j < 10; j++)
      if (j == 0)
        dp[i][j] = dp[i - 1][j + 1];
      else if (j == 9)
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = (dp[i - 1][j - 1] % 1000000000 + dp[i - 1][j + 1] % 1000000000) % 1000000000;
  int sum = 0;
  for (int i = 0; i < 10; i++)
    sum = (sum % 1000000000 + dp[n][i] % 1000000000) % 1000000000;
  cout << sum;
  return 0;
}