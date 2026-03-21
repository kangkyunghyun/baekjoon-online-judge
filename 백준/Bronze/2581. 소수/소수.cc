#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n, sum = 0, min;
  cin >> m >> n;
  min = n;
  for (int i = m; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j < i; j++) {
      if (i % j == 0) {
        cnt++;
      }
    }
    if (cnt == 1) {
      sum += i;
      if (i < min)
        min = i;
    }
  }
  if (sum != 0) {
    cout << sum << '\n'
         << min << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}