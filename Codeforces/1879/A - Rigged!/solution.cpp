#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int x, y;
    cin >> x >> y;
    v.push_back({x, y});
    for (int i = 1; i < n; i++) {
      cin >> x >> y;
      if (y >= v[0].second)
        v.push_back({x, y});
    }
    sort(v.begin() + 1, v.end());
    if (v.size() == 1)
      cout << v[0].first << '
';
    else if (v.back().first >= v[0].first)
      cout << -1 << '
';
    else
      cout << v.back().first + 1 << '
';
  }
  return 0;
}