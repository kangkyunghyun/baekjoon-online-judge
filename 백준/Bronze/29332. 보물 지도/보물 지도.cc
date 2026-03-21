#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, l = INT_MAX, r = -INT_MAX, u = -INT_MAX, d = INT_MAX;
  cin >> n;
  set<char> s;
  while (n--) {
    ll x, y;
    char c;
    cin >> x >> y >> c;
    s.insert(c);
    if (c == 'L')
      l = min(l, x);
    else if (c == 'R')
      r = max(r, x);
    else if (c == 'U')
      u = max(u, y);
    else if (c == 'D')
      d = min(d, y);
  }
  if (s.size() != 4)
    cout << "Infinity";
  else
    cout << (d - u - 1) * (l - r - 1);
  return 0;
}