#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, a, ans = 0;
  cin >> t;
  for (int i = 0; i < 5; i++) {
    cin >> a;
    if (a == t)
      ans++;
  }
  cout << ans;
  return 0;
}