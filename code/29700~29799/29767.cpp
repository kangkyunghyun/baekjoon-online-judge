#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, k, ans = 0;
  cin >> n >> k;
  vector<ll> a(n + 1, 0);
  vector<pair<ll, ll>> b(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
    b[i - 1] = {a[i], i};
  }
  sort(b.begin(), b.end(), greater<>());
  for (int i = 0; i < k; i++)
    ans += a[b[i].second];
  cout << ans;
  return 0;
}