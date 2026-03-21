#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int l, a, b, c, d, x;
  cin >> l >> a >> b >> c >> d;
  if (a / c > b / d) {
    if (a % c == 0)
      x = a / c;
    else
      x = a / c + 1;
  } else {
    if (b % d == 0)
      x = b / d;
    else
      x = b / d + 1;
  }
  cout << l - x << '\n';
  return 0;
}