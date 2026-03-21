#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<long long>> v(m, vector<long long>(n, 0));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> v[i][j];
  vector<long long> f(n, 0);
  for (int i = 0; i < n; i++) {
    vector<long long> tmp;
    for (int j = 0; j < m; j++)
      tmp.push_back(v[j][i]);
    sort(tmp.begin(), tmp.end());
    if (m % 2)
      f[i] = tmp[m / 2];
    else
      f[i] = (tmp[m / 2] + tmp[m / 2 - 1]) / 2;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      ans += abs(f[i] - v[j][i]);
  cout << ans << '\n';
  for (long long i : f)
    cout << i << ' ';
  return 0;
}