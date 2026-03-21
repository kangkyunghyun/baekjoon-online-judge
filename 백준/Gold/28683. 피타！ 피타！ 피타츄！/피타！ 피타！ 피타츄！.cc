#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  if (sqrt(n) == (ll)sqrt(n)) {
    cout << -1;
    return 0;
  }
  set<pair<ll, ll>> ans;
  for (ll i = 1; i <= sqrt(n); i++) {
    ll x = i;
    double y = sqrt(n - x * x);
    ll tmp = y;
    if (y == tmp) {
      if (x > tmp)
        swap(x, tmp);
      ans.insert({x, tmp});
    }
  }
  vector<ll> divisor;
  for (ll i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      divisor.push_back(i);
      if (i != n / i)
        divisor.push_back(n / i);
    }
  }
  sort(divisor.begin(), divisor.end());
  for (ll i = 0; i < (divisor.size() + 1) / 2; i++) {
    if (divisor[i] % 2 == divisor[divisor.size() - i - 1] % 2)
      ans.insert({divisor[i], divisor[divisor.size() - i - 1]});
  }
  cout << ans.size();
  return 0;
}