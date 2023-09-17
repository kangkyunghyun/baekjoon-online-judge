#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

bool cmp(pii a, pii b) {
  return abs(a.first - a.second) > abs(b.first - b.second);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, a, b;
  cin >> n >> a >> b;
  vector<pii> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end(), cmp);
  int dong = 0, ji = 0;
  long long ans = 0;
  for (auto [x, y] : p) {
    if (x > y) {
      if (ji < b) {
        ji++;
        ans += y;
      } else {
        dong++;
        ans += x;
      }
    } else {
      if (dong < a) {
        dong++;
        ans += x;
      } else {
        ji++;
        ans += y;
      }
    }
  }
  cout << ans;
}