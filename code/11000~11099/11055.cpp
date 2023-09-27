#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  vector<int> dp{v};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (v[j] < v[i] && dp[i] < dp[j] + v[i])
        dp[i] = max(dp[i], dp[j] + v[i]);
  cout << *max_element(dp.begin(), dp.end());
  return 0;
}