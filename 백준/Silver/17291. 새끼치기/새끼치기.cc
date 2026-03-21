#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, a[21] = {0, 1, 2, 4, 7};
  cin >> n;
  for (int i = 5; i <= n; i++) {
    a[i] = a[i - 1] * 2;
    if (!(i & 1))
      a[i] -= a[i - 4] + a[i - 5];
  }
  cout << a[n];
  return 0;
}