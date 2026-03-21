#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<ll> v(n + 1, 0), dp(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] += v[i - 1];
  }
  dp[1] = max(0, (int)v[1]);
  for (int i = 2; i <= n; i++)
    dp[i] = max(dp[i - 1], v[i] - dp[i - 1]);
  cout << dp[n];
  return 0;
}