#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  int cnt = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x)
      cnt++;
    else {
      ans = max(ans, cnt);
      cnt = 0;
    }
  }
  ans = max(ans, cnt);
  cout << ans;
  return 0;
}