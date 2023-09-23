#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int g;
    cin >> g;
    int t = g * 100 / n, ans;
    if (t >= 0 && t <= 4)
      ans = 1;
    else if (t > 4 && t <= 11)
      ans = 2;
    else if (t > 11 && t <= 23)
      ans = 3;
    else if (t > 23 && t <= 40)
      ans = 4;
    else if (t > 40 && t <= 60)
      ans = 5;
    else if (t > 60 && t <= 77)
      ans = 6;
    else if (t > 77 && t <= 89)
      ans = 7;
    else if (t > 89 && t <= 96)
      ans = 8;
    else if (t > 96 && t <= 100)
      ans = 9;
    cout << ans << ' ';
  }
  return 0;
}