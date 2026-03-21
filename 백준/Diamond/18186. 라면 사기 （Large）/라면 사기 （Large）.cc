#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, b, c, ans = 0, cnt;
  cin >> n >> b >> c;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  if (b < c) {
    for (int i = 0; i < n; i++)
      ans += v[i];
    ans *= b;
  } else {
    for (int i = 0; i < n - 2; i++) {
      while (v[i] && v[i + 1] && v[i + 2]) {
        if (v[i + 1] > v[i + 2]) {
          cnt = min(v[i], v[i + 1] - v[i + 2]);
          v[i] -= cnt;
          v[i + 1] -= cnt;
          ans += (b + c) * cnt;
        } else {
          cnt = min(v[i], v[i + 1]);
          v[i] -= cnt;
          v[i + 1] -= cnt;
          v[i + 2] -= cnt;
          ans += (b + 2 * c) * cnt;
        }
      }
      ans += b * v[i];
      v[i] = 0;
    }
    cnt = min(v[n - 2], v[n - 1]);
    ans += (b + c) * cnt;
    v[n - 2] -= cnt;
    v[n - 1] -= cnt;
    ans += b * (v[n - 2] + v[n - 1]);
  }
  cout << ans;
  return 0;
}