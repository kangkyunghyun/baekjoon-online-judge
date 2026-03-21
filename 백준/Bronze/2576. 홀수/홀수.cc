#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, sum = 0, m = 100;
  for (int i = 0; i < 7; i++) {
    cin >> a;
    if (a & 1) {
      sum += a;
      m = min(m, a);
    }
  }
  if (sum)
    cout << sum << '\n';
  cout << (m == 100 ? -1 : m);
  return 0;
}