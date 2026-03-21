#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin >> n >> x;
  vector<int> v{x}, LIS{x}, idx{1};
  for (int i = 1; i < n; i++) {
    cin >> x;
    v.push_back(x);
    if (LIS.back() < x) {
      LIS.push_back(x);
      idx.push_back(LIS.size());
    } else {
      auto it = lower_bound(LIS.begin(), LIS.end(), x);
      *it = x;
      idx.push_back(it - LIS.begin() + 1);
    }
  }
  int size = LIS.size();
  cout << size << '\n';
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--)
    if (idx[i] == size) {
      ans.push_back(v[i]);
      size--;
    }
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}