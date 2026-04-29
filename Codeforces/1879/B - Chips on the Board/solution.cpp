#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll sum_a = 0, sum_b = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum_a += a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      sum_b += b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = min(a[0] * n + sum_b, b[0] * n + sum_a);
    cout << ans << '
';
  }
  return 0;
}