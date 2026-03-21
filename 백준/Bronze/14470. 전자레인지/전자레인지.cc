#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int a, b, c, d, e, ans = 0;
  cin >> a >> b >> c >> d >> e;
  bool iced = false;
  while (a != b) {
    if (a < 0) {
      a++;
      iced = true;
      ans += c;
    } else if (a == 0 && iced) {
      iced = false;
      ans += d;
    } else {
      a++;
      ans += e;
    }
  }
  cout << ans;
  return 0;
}