#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> v(501, vector<int>(501, 0)), dp(501, vector<int>(501, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      cin >> v[i][j];
  dp[0][0] = v[0][0];
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j <= i + 1; j++)
      dp[i + 1][j] = max(dp[i][j], dp[i][j - 1]) + v[i + 1][j];
  cout << *max_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
  return 0;
}