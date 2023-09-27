#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int a, b, c;
  cin >> a >> b >> c;
  int x1, x2, y1, y2;
  cin >> x1 >> x2 >> y1 >> y2;
  vector<pair<int, int>> v;
  v.push_back({x1, y1});
  v.push_back({x1, y2});
  v.push_back({x2, y1});
  v.push_back({x2, y2});
  int u = 0, d = 0;
  for (auto i : v) {
    if (a * i.first + b * i.second <= -c)
      d++;
    if (a * i.first + b * i.second >= -c)
      u++;
  }
  if (u == 4 || d == 4)
    cout << "Lucky";
  else
    cout << "Poor";
  return 0;
}