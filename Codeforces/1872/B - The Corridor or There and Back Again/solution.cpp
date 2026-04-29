#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, ans = INT_MAX;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      int d, s;
      cin >> d >> s;
      int t = d - 1 + s;
      int k = 1;
      while (k - 1 + k - d < t)
        k++;
      ans = min(ans, k - 1);
    }
    cout << ans << '
';
  }
  return 0;
}