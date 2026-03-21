#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int a, b, h, sum = 0, ans = 0;
  cin >> a >> b >> h;
  while (1) {
    sum += a;
    ans++;
    if (sum >= h)
      break;
    sum -= b;
  }
  cout << ans;
  return 0;
}