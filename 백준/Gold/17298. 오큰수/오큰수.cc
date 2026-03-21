#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n), s, ans(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = n - 1; i >= 0; i--) {
    if (s.empty()) {
      ans[i] = -1;
      s.push_back(v[i]);
    } else {
      while (!s.empty() && s.back() <= v[i]) {
        s.pop_back();
      }
      if (s.empty()) {
        ans[i] = -1;
        s.push_back(v[i]);
      } else {
        ans[i] = s.back();
        s.push_back(v[i]);
      }
    }
  }
  for (int i : ans)
    cout << i << ' ';
  return 0;
}