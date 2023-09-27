#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    vector<pair<int, int>> v(4);
    for (int i = 0; i < 4; i++)
      cin >> v[i].first >> v[i].second;
    vector<int> a;
    for (int i = 0; i < 4; i++)
      for (int j = i + 1; j < 4; j++)
        a.push_back((v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second));
    sort(a.begin(), a.end());
    cout << (a[0] == a[1] && a[1] == a[2] && a[2] == a[3] && a[4] == a[5]) << '\n';
  }
  return 0;
}