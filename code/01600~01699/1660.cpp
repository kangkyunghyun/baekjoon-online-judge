#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v(121, 0), dp(3000001, INF);
  for (int i = 1; i <= 120; i++)
    v[i] = v[i - 1] + i * (i + 1) / 2;
  int n;
  cin >> n;
  dp[0] = 0;
  for (int i = 0; i < v.size(); i++)
    for (int j = v[i]; j <= n; j++)
      dp[j] = min(dp[j], dp[j - v[i]] + 1);
  cout << dp[n];
  return 0;
}