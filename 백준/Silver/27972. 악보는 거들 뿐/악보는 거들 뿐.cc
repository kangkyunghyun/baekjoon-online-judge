#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, a = 1, b = 1, ans = 0;
  cin >> m;
  vector<int> v(m, 0);
  for (int i = 0; i < m; i++) {
    cin >> v[i];
    if (i == 0)
      continue;
    if (a == 1 && b == 1) {
      if (v[i] > v[i - 1]) {
        a++;
      } else if (v[i] < v[i - 1]) {
        b++;
      }
    } else if (a > 1) {
      if (v[i] > v[i - 1]) {
        a++;
      } else if (v[i] < v[i - 1]) {
        b++;
        ans = max(ans, a);
        a = 1;
      }
    } else {
      if (v[i] > v[i - 1]) {
        a++;
        ans = max(ans, b);
        b = 1;
      } else if (v[i] < v[i - 1]) {
        b++;
      }
    }
  }
  ans = max(ans, max(a, b));
  cout << ans;
  return 0;
}