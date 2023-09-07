#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  ll ans = 0;
  cin >> n;
  map<int, ll> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (m.empty()) {
      m[x] = 1;
      ans = 1;
    } else {
      auto it = m.lower_bound(x);
      ll tmp = 0;
      if (it != m.end())
        tmp = max(tmp, it->second);
      if (it != m.begin()) {
        it--;
        tmp = max(tmp, it->second);
      }
      ans += tmp + 1;
      m[x] = tmp + 1;
    }
  }
  cout << ans;
  return 0;
}