#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s.insert(a);
    }
    int x = 0, y;
    for (auto i : s)
      if (i == x)
        x++;
    while (1) {
      cout << x << endl;
      s.insert(x);
      cin >> y;
      if (y == -1)
        break;
      s.erase(y);
      if (y <= x)
        x = y;
      else {
        x = 0;
        for (auto i : s)
          if (i == x)
            x++;
      }
    }
  }
  return 0;
}