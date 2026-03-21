#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n - 2; i++) {
    while (v[i] && v[i + 1] && v[i + 2]) {
      if (v[i + 1] > v[i + 2]) {
        int cnt = min(v[i], v[i + 1] - v[i + 2]);
        v[i] -= cnt;
        v[i + 1] -= cnt;
        ans += 5 * cnt;
      } else {
        int cnt = min(v[i], v[i + 1]);
        v[i] -= cnt;
        v[i + 1] -= cnt;
        v[i + 2] -= cnt;
        ans += 7 * cnt;
      }
    }
    ans += 3 * v[i];
    v[i] = 0;
  }
  int g = min(v[n - 2], v[n - 1]);
  ans += 5 * g;
  v[n - 2] -= g;
  v[n - 1] -= g;
  ans += 3 * (v[n - 2] + v[n - 1]);
  cout << ans;
  return 0;
}