#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  vector<int> dp(n, 1);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v[i] = {a, b};
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (v[j].second < v[i].second)
        dp[i] = max(dp[i], dp[j] + 1);
  cout << n - *max_element(dp.begin(), dp.end()) << '\n';
  return 0;
}