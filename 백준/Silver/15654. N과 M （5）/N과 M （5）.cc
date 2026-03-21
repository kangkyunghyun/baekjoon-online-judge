#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans(8, 0), v, visited(9, 0);

void dfs(int cnt) {
  if (cnt == m) {
    for (int i = 0; i < m; i++)
      cout << ans[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; i++)
    if (!visited[i]) {
      visited[i] = 1;
      ans[cnt] = v[i];
      dfs(cnt + 1);
      visited[i] = 0;
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