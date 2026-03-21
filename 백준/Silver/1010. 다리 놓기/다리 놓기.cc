#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    long long ans = 1;
    int r = 1;
    for (int i = m; i > m - n; i--) {
      ans *= i;
      ans /= r++;
    }
    cout << ans << '\n';
  }
  return 0;
}