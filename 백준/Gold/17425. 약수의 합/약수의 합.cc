#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<long long> sieve(1000001, 0), dp(1000001, 0);
  for (int i = 1; i <= 1000000; i++)
    for (int j = i; j <= 1000000; j += i)
      sieve[j] += i;
  for (int i = 1; i <= 1000000; i++)
    dp[i] = dp[i - 1] + sieve[i];
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << dp[n] << '\n';
  }
  return 0;
}