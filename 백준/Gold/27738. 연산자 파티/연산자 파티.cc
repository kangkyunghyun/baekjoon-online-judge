#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, b, c, d, e, f;
  long long x = 0;
  cin >> n >> a >> b >> c >> d >> e >> f;
  for (int i = 1; i <= n; i++) {
    if (i % a == 0)
      x += i;
    if (i % b == 0)
      x %= i;
    if (i % c == 0)
      x = x & i;
    if (i % d == 0)
      x = x ^ i;
    if (i % e == 0)
      x = x | i;
    if (i % f == 0)
      x = x >> i;
  }
  cout << x << '\n';
  return 0;
}