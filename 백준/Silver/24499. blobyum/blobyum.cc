#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, ans = 0;
  cin >> n >> k;
  vector<int> v(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    v[i] += v[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    int j = i + k - 1;
    if (j > n) {
      j -= n;
      ans = max(ans, v[n] - v[i - 1] + v[j]);
    } else {
      ans = max(ans, v[j] - v[i - 1]);
    }
  }
  cout << ans;
  return 0;
}