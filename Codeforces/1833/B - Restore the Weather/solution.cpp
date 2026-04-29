#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), ans(n);
    vector<pair<int, int>> x(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    for (int i = 0; i < n; i++)
      x[i] = {a[i], i};
    sort(b.begin(), b.end());
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++)
      ans[x[i].second] = b[i];
    for (int i = 0; i < n; i++)
      cout << ans[i] << ' ';
    cout << '
';
  }
  return 0;
}