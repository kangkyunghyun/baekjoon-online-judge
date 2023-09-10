#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  long long dp[36];
  dp[0] = 1;
  for (int i = 1; i <= 35; i++) {
    long long sum = 0;
    for (int j = 0; j < i; j++)
      sum += dp[j] * dp[i - 1 - j];
    dp[i] = sum;
  }
  cout << dp[n];
  return 0;
}