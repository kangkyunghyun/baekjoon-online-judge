#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    map<string, int> m;
    string name, type;
    int n, ans = 1;
    cin >> n;
    while (n--) {
      cin >> name >> type;
      if (m.find(type) == m.end())
        m[type] = 1;
      else
        m[type]++;
    }
    for (auto i : m)
      ans *= i.second + 1;
    cout << ans - 1 << '\n';
  }
  return 0;
}