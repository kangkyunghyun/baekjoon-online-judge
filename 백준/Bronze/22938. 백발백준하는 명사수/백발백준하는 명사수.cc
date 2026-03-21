#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  cout << (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) < r1 + r2 ? "YES" : "NO");
  return 0;
}