#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  set<pair<double, int>> s;
  for (int i = 0; i < n; i++) {
    double x, y;
    cin >> x >> y;
    double t = 0;
    int a;
    if (x > 0 && y > 0) {
      a = 1;
      t = y / x;
    } else if (x < 0 && y > 0) {
      a = 2;
      t = y / x;
    } else if (x < 0 && y < 0) {
      a = 3;
      t = y / x;
    } else if (x > 0 && y < 0) {
      a = 4;
      t = y / x;
    } else if (x == 0 && y > 0)
      a = 5; // y축 위
    else if (x == 0 && y < 0)
      a = 6; // y축 아래
    else if (y == 0 && x > 0)
      a = 7; // x축 오른쪽
    else if (y == 0 && x > 0)
      a = 8; // x축 왼쪽
    s.insert({t, a});
  }
  cout << s.size();
  return 0;
}
