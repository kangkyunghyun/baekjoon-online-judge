#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m = 1001, a, b;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    if (a <= b)
      m = min(m, b);
  }
  cout << (m > 1000 ? -1 : m);
  return 0;
}