#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int w, h, x, y, p, ans = 0;
  cin >> w >> h >> x >> y >> p;
  while (p--) {
    int a, b;
    cin >> a >> b;
    if (a >= x && a <= x + w && b >= y && b <= y + h)
      ans++;
    else if (pow((double)a - x, 2) + pow((double)b - y - (double)h / 2, 2) <= pow((double)h / 2, 2) || pow((double)a - x - w, 2) + pow((double)b - y - (double)h / 2, 2) <= pow((double)h / 2, 2))
      ans++;
  }
  cout << ans;
  return 0;
}