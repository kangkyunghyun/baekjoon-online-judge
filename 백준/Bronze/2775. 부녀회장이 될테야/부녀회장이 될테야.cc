#include <bits/stdc++.h>
using namespace std;
int dp[15][15];

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
      for (int j = 1; j <= k; j++)
        if (i == 0)
          dp[0][j] = j;
        else if (j == 1)
          dp[i][1] = 1;
        else
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    cout << dp[n][k] << '\n';
  }
  return 0;
}