#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, x;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> x;
    auto upper = upper_bound(v.begin(), v.end(), x);
    auto lower = lower_bound(v.begin(), v.end(), x);
    cout << upper - lower << ' ';
  }
  return 0;
}