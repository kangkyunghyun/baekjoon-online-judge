#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  double d1, d2;
  cin >> d1 >> d2;
  double ans = 2 * d1 + 2 * PI * d2;
  cout.precision(6);
  cout << fixed << ans;
  return 0;
}