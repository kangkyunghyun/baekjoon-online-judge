#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      v[i] = v[i - 1] + x;
    }
    while (q--) {
      int l, r, k;
      cin >> l >> r >> k;
      int sum = v[l - 1];
      sum += k * (r - l + 1);
      sum += v[n] - v[r];
      if (sum % 2)
        cout << "YES
";
      else
        cout << "NO
";
    }
  }
  return 0;
}