#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> v(n + 1), l(n, 0), r(n, 0);
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  for (int i = 1; i <= n - 1; i++) {
    cin >> l[i];
    l[i] += l[i - 1];
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> r[i];
    r[i] += r[i - 1];
  }
  ll d = v[1] + r[n - 1];
  int idx = 1;
  for (int i = 2; i <= n; i++) {
    ll sum = v[i] + l[i - 1] + r[n - 1] - r[i - 1];
    if (sum < d) {
      d = sum;
      idx = i;
    }
  }
  cout << idx << ' ' << d;
  return 0;
}