#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> ans(n);
  vector<pair<int, int>> v, s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(make_pair(i + 1, x));
  }
  for (int i = 0; i < n; i++) {
    if (s.empty()) {
      ans[i] = 0;
      s.push_back(v[i]);
    } else {
      while (!s.empty() && s.back().second <= v[i].second)
        s.pop_back();
      if (s.empty())
        ans[i] = 0;
      else
        ans[i] = s.back().first;
      s.push_back(v[i]);
    }
  }
  for (int i : ans)
    cout << i << ' ';
  return 0;
}