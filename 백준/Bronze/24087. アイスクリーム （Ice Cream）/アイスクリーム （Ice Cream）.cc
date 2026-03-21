#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int s, a, b, ans = 250;
  cin >> s >> a >> b;
  while (a < s) {
    a += b;
    ans += 100;
  }
  cout << ans;
  return 0;
}