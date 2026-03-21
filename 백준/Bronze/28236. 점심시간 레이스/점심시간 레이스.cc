#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k, ans, t = 200001;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    int f, d;
    cin >> f >> d;
    int s = f + m - d;
    if (s < t) {
      ans = i;
      t = s;
    }
  }
  cout << ans;
  return 0;
}