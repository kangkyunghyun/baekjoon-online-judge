#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n), dp(n, 1);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (v[j] > v[i])
        dp[i] = max(dp[i], dp[j] + 1);
  cout << *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}