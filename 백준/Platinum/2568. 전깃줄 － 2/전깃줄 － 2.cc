#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  vector<int> LIS, idx(n);
  for (int i = 0; i < n; i++)
    cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());
  LIS.push_back(v[0].second);
  idx[0] = 1;
  for (int i = 1; i < n; i++) {
    if (LIS.back() < v[i].second) {
      LIS.push_back(v[i].second);
      idx[i] = LIS.size();
    } else {
      auto it = lower_bound(LIS.begin(), LIS.end(), v[i].second);
      *it = v[i].second;
      idx[i] = it - LIS.begin() + 1;
    }
  }
  int size = LIS.size();
  cout << n - size << '\n';
  for (int i = n - 1; i >= 0; i--)
    if (idx[i] == size) {
      idx[i] = 0;
      size--;
    }
  for (int i = 0; i < n; i++)
    if (idx[i])
      cout << v[i].first << '\n';
  return 0;
}