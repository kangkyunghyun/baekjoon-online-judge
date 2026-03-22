#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> v(n);
  set<vector<int>> ans;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++) {
    string a = v[i];
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      string b = v[j];
      for (int k = 1; k <= min(a.size(), b.size()); k++)
        if (b.substr(0, k) == a.substr(a.size() - k, k)) {
          vector<int> tmp{i, j};
          sort(tmp.begin(), tmp.end());
          ans.insert(tmp);
          break;
        }
    }
  }
  cout << ans.size();
  return 0;
}