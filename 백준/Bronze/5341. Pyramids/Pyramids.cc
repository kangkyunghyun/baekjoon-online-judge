#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  while (1) {
    int x, ans = 0;
    cin >> x;
    if (x == 0)
      break;
    while (x > 0) {
      ans += x;
      x--;
    }
    cout << ans << '\n';
  }
  return 0;
}