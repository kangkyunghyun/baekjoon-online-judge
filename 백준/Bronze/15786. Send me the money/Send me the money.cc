#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  string a, b;
  cin >> n >> m >> a;
  while (m--) {
    cin >> b;
    int idx = 0, flag = 0;
    for (int i = 0; i < n; i++) {
      if (b.find(a[i], idx) != -1)
        idx = b.find(a[i], idx) + 1;
      else {
        flag = 1;
        break;
      }
    }
    if (flag)
      cout << "false\n";
    else
      cout << "true\n";
  }
  return 0;
}