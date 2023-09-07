#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define piii pair<pii, int>

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<piii> v;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back({{x, y}, i + 1});
  }
  sort(v.begin(), v.end());
  vector<piii> tmp;
  double m = 0;
  for (int i = 0; i < n - 1; i++) {
    piii a = v[i];
    piii b = v[i + 1];
    double l = abs((double)(b.first.second - a.first.second) / (b.first.first - a.first.first));
    if (m > l)
      continue;
    if (m < l) {
      m = l;
      tmp.clear();
    }
    if (a.second > b.second)
      swap(a, b);
    tmp.push_back(a);
  }
  sort(tmp.begin(), tmp.end(), [](piii a, piii b) { return a.second < b.second; });
  vector<pii> ans;
  m = 0;
  for (int i = 0; i < n; i++) {
    piii a = tmp[0];
    piii b = v[i];
    if (a == b)
      continue;
    double l = abs((double)(b.first.second - a.first.second) / (b.first.first - a.first.first));
    if (m > l)
      continue;
    if (m < l) {
      m = l;
      ans.clear();
    }
    if (a.second > b.second)
      swap(a.second, b.second);
    ans.push_back({a.second, b.second});
  }
  sort(ans.begin(), ans.end());
  cout << ans[0].first << ' ' << ans[0].second;
  return 0;
}