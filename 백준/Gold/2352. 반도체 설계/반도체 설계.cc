#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  vector<int> LIS, idx(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = {i + 1, x};
  }
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
  cout << LIS.size() << '\n';
  return 0;
}