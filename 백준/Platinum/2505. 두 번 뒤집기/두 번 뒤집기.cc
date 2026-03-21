#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> input(n), v;
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++)
    cin >> input[i];
  v = input;
  for (int i = 0; i < n; i++) {
    if (v[i] == i + 1)
      continue;
    for (int j = i + 1; j < n; j++)
      if (v[j] == i + 1) {
        ans.push_back({i + 1, j + 1});
        reverse(v.begin() + i, v.begin() + j + 1);
        break;
      }
  }
  if (ans.size() > 2) {
    ans.clear();
    v = input;
    for (int j = n - 1; j >= 0; j--) {
      if (v[j] == j + 1)
        continue;
      for (int i = j - 1; i >= 0; i--)
        if (v[i] == j + 1) {
          ans.push_back({i + 1, j + 1});
          reverse(v.begin() + i, v.begin() + j + 1);
          break;
        }
    }
  }
  if (ans.size() == 2)
    for (auto [a, b] : ans)
      cout << a << ' ' << b << '\n';
  else if (ans.size() == 1)
    cout << ans[0].first << ' ' << ans[0].second << "\n1 1";
  else
    cout << "1 1\n1 1";
  return 0;
}