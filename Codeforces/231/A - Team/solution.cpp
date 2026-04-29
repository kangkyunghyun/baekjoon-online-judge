#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    int cnt = 0;
    for (int j = 0; j < 3; j++) {
      cin >> x;
      if (x)
        cnt++;
    }
    if (cnt > 1)
      ans++;
  }
  cout << ans;
}