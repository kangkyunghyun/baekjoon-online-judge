#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int x, ans = 0;
  while (cin >> s >> x)
    if (s == "Es")
      ans += 21 * x;
    else
      ans += 17 * x;
  cout << ans;
  return 0;
}