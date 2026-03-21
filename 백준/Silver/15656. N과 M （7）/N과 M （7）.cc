#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans(7, 0), v;

void dfs(int cnt) {
  if (cnt == m) {
    for (int i = 0; i < m; i++)
      cout << ans[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    ans[cnt] = v[i];
    dfs(cnt + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  dfs(0);
  return 0;
}