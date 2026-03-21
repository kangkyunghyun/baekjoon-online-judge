#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, x, cnt = 0;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 0; i <= n; i++) {
    cin >> v[i];
    if (v[i] == 1)
      cnt++;
  }
  cin >> x;
  if (cnt > 2) {
    cout << "NO\n";
    return 0;
  }
  if (cnt == 1) {
    int idx = -1;
    for (int i = 0; i <= n; i++)
      if (v[i] == 1) {
        idx = i;
        break;
      }
    if (idx - x >= 0 && v[idx - x] - 1 >= 2) {
      cout << "YES\n"
           << idx - x << ' ' << idx << '\n';
    } else if (idx + x <= n && v[idx + x] + 1 >= 2) {
      cout << "YES\n"
           << idx << ' ' << idx + x << '\n';
    } else
      cout << "NO\n";
  } else if (cnt == 2) {
    int a = -1, b = -1;
    for (int i = 0; i <= n; i++)
      if (v[i] == 1) {
        if (a == -1)
          a = i;
        else
          b = i;
      }
    if (b - a == x)
      cout << "YES\n"
           << a << ' ' << b << '\n';
    else
      cout << "NO\n";
  } else {
    for (int i = 0; i <= n - x; i++) {
      if (v[i] - 1 >= 2 && v[i + x] + 1 >= 2) {
        cout << "YES\n"
             << i << ' ' << i + x << '\n';
        return 0;
      }
    }
    cout << "NO\n";
  }
  return 0;
}