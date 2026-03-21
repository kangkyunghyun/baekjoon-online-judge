#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (1) {
    int b, n;
    cin >> b >> n;
    if (b + n == 0)
      break;
    int ans = 0, a = 1;
    while (1) {
      int curr = abs(b - (int)pow(a, n));
      int prev = abs(b - (int)pow(ans, n));
      if (curr < prev)
        ans = a;
      else
        break;
      a++;
    }
    cout << ans << '\n';
  }
  return 0;
}