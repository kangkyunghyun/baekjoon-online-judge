#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int m;
  cin >> m;
  vector<int> v(21, 0);
  while (m--) {
    string s;
    cin >> s;
    if (s == "add") {
      int x;
      cin >> x;
      if (!v[x])
        v[x] = 1;
    } else if (s == "remove") {
      int x;
      cin >> x;
      if (v[x])
        v[x] = 0;
    } else if (s == "check") {
      int x;
      cin >> x;
      if (v[x])
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    } else if (s == "toggle") {
      int x;
      cin >> x;
      if (v[x])
        v[x] = 0;
      else
        v[x] = 1;
    } else if (s == "all") {
      for (int i = 1; i <= 20; i++)
        v[i] = 1;
    } else if (s == "empty") {
      for (int i = 1; i <= 20; i++)
        v[i] = 0;
    }
  }
  return 0;
}