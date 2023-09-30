#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int a = 0, b = 0, x, y;
    for (int i = 0; i < 9; i++) {
      cin >> x >> y;
      a += x;
      b += y;
    }
    if (a > b)
      cout << "Yonsei";
    else if (a < b)
      cout << "Korea";
    else
      cout << "Draw";
    cout << '\n';
  }
}