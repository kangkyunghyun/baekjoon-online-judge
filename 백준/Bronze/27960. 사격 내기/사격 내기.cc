#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int sa, sb;
  cin >> sa >> sb;
  vector<int> a(10, 0), b(10, 0);
  int d = 512;
  while (d > 0) {
    if (sa >= d) {
      a[log2(d)]++;
      sa -= d;
    }
    d /= 2;
  }
  d = 512;
  while (d > 0) {
    if (sb >= d) {
      b[log2(d)]++;
      sb -= d;
    }
    d /= 2;
  }
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    if ((a[i] && b[i]) || (!a[i] && !b[i]))
      continue;
    ans += pow(2, i);
  }
  cout << ans;
  return 0;
}