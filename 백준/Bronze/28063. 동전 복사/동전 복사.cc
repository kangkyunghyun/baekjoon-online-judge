#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, y, ans = 0;
  cin >> n >> x >> y;
  if (n == 1)
    ans = 0;
  else if (x == 1 || x == n) {
    if (y == 1 || y == n)
      ans = 2;
    else
      ans = 3;
  } else {
    if (y == 1 || y == n)
      ans = 3;
    else
      ans = 4;
  }
  cout << ans;
  return 0;
}