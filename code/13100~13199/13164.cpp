#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int ans = v[n - 1] - v[0];
  for (int i = n - 1; i > 0; i--)
    v[i] -= v[i - 1];
  v[0] = 0;
  sort(v.begin(), v.end());
  for (int i = n - 1; --k; i--)
    ans -= v[i];
  cout << ans;
  return 0;
}