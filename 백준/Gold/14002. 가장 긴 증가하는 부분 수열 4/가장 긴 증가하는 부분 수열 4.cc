#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n), dp(n, 1), prev(n, -1);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (v[i] > v[j]) {
        if (dp[i] < dp[j] + 1)
          prev[i] = j;
        dp[i] = max(dp[i], dp[j] + 1);
      }
  int idx = 0, m = 0;
  for (int i = 0; i < n; i++)
    if (dp[i] > m) {
      m = dp[i];
      idx = i;
    }
  cout << m << '\n';
  int tmp = idx;
  vector<int> ans;
  while (tmp >= 0) {
    ans.push_back(v[tmp]);
    tmp = prev[tmp];
  }
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}