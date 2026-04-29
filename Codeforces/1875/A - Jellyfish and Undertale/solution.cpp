#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, n;
    cin >> a >> b >> n;
    int ans = b, cnt = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      ans += min(a, x);
      if (x >= a)
        cnt++;
    }
    cout << ans - cnt << '
';
  }
}