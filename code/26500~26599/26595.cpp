#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, a, b, c, d, e = 0, f = 0, m = 0;
  cin >> n >> a >> b >> c >> d;
  for (long long i = 0; i <= n / b; i++) {
    long long now = a * i + c * ((n - b * i) / d);
    if (now > m) {
      m = now;
      e = i;
      f = (n - b * i) / d;
    }
  }
  cout << e << ' ' << f;
  return 0;
}