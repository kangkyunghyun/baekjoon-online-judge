#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<ll> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  while (k--) {
    int l, r, x;
    cin >> l >> r >> x;
    for (int i = l - 1; i < r; i++)
      v[i] += x;
    if (x > 0)
      sort(v.begin() + l - 1, v.end());
    else if (x < 0)
      sort(v.begin(), v.begin() + r);
  }
  for (ll i : v)
    cout << i << ' ';
  return 0;
}