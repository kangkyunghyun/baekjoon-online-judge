#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].first >> v[i].second;
  set<pair<double, int>> s;
  for (auto [x, y] : v) {
    double t = 0;
    int a;
    if (x > 0 && y > 0) {
      a = 1;
      t = (double)y / x;
    } else if (x < 0 && y > 0) {
      a = 2;
      t = (double)y / x;
    } else if (x < 0 && y < 0) {
      a = 3;
      t = (double)y / x;
    } else if (x > 0 && y < 0) {
      a = 4;
      t = (double)y / x;
    } else if (x == 0)
      a = 5; // y축
    else if (y == 0)
      a = 6; // x축
    s.insert({t, a});
  }
  cout << s.size();
  return 0;
}