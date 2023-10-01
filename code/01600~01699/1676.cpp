#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, ans = 0;
  cin >> n;
  for (int i = 5; i <= n; i *= 5)
    ans += n / i;
  cout << ans;
}