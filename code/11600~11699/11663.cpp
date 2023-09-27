#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  while (m--) {
    int a, b;
    cin >> a >> b;
    auto x = lower_bound(v.begin(), v.end(), b);
    auto y = lower_bound(v.begin(), v.end(), a);
    int ans = x - y + 1;
    if (*x != b)
      ans--;
    cout << ans << '\n';
  }
  return 0;
}