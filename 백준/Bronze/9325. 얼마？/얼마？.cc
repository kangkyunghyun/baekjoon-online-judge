#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, s, n, q, p, sum = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> s >> n;
    sum = s;
    for (int j = 0; j < n; j++) {
      cin >> q >> p;
      sum += q * p;
    }
    cout << sum << '\n';
  }
  return 0;
}