#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sort(v[i].begin(), v[i].end());
  }
  sort(v.begin(), v.end());
  string ans = "";
  for (int i = 0; i < k; i++)
    ans += v[i];
  sort(ans.begin(), ans.end());
  cout << ans;
  return 0;
}