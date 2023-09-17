#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> v(n + 1, 0);
  while (m--) {
    int k, s, e;
    cin >> k >> s >> e;
    if (v[k] <= s) {
      v[k] = e;
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}