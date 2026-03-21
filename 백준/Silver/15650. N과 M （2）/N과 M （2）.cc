#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v(8, 0), visited(9, 0);

void dfs(int cnt) {
  if (cnt == m) {
    for (int i = 0; i < m; i++)
      cout << v[i] << ' ';
    cout << '\n';
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i] && i > v[cnt - 1]) {
      visited[i] = 1;
      v[cnt] = i;
      dfs(cnt + 1);
      visited[i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  dfs(0);
  return 0;
}