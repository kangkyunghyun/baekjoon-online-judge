#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int start = 0, end = 0;
  while (end <= n) {
    int sum = 0;
    for (int i = start; i <= end; i++)
      sum += v[i];
    if (sum < m)
      end++;
    else if (sum >= m)
      start++;
    if (sum == m)
      ans++;
  }
  cout << ans;
  return 0;
}