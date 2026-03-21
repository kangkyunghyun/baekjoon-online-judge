#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int x, y, ans = 0;
    cin >> x >> y;
    int gap = y - x, h = 1;
    while (gap) {
      gap -= 2 * h;
      ans += 2;
      if (gap <= h) {
        while (gap != 0) {
          if (gap < 0) {
            gap += h;
            ans--;
            h--;
          } else if (gap > 0) {
            gap -= h;
            ans++;
            h++;
          }
        }
      }
      h++;
    }
    cout << ans << '\n';
  }
  return 0;
}