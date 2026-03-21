#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, flag = 0;
    cin >> n;
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      m[x].push_back(y);
    }
    for (auto &i : m)
      sort(i.second.begin(), i.second.end());
    for (auto i : m) {
      if (flag)
        break;
      for (auto j : m) {
        if (i.first == j.first)
          continue;
        if (i.second != j.second) {
          flag = 1;
          break;
        }
      }
    }
    cout << (flag ? "NOT BALANCED\n" : "BALANCED\n");
  }
  return 0;
}