#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (ll i = 0; i < n; i++)
    cin >> a[i];
  for (ll i = 0; i < m; i++)
    cin >> b[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll cool = -1;
  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    if (cool <= a[i]) {
      cnt++;
      cool = a[i] + 100;
    }
  }
  cout << cnt << ' ';

  cool = -1;
  cnt = 0;
  for (ll i = 0; i < m; i++) {
    if (cool <= b[i]) {
      cnt++;
      cool = b[i] + 360;
    }
  }
  cout << cnt;

  return 0;
}