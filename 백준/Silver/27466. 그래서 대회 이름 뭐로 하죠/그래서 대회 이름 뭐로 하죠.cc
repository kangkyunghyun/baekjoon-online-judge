#include <bits/stdc++.h>
using namespace std;

int n, m, a = 0, flag = 0;
string s;
vector<int> visited(300001, 0);
vector<char> ans(300001);

void dfs(int cnt) {
  if (cnt == m) {
    if (ans[m - 2] == 'A' && ans[m - 3] == 'A' && (ans[m - 1] != 'A' && ans[m - 1] != 'E' && ans[m - 1] != 'I' && ans[m - 1] != 'O' && ans[m - 1] != 'U')) {
      cout << "YES\n";
      for (int i = 0; i < m; i++)
        cout << ans[i];
      cout << '\n';
      flag = 1;
    }
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!visited[i] && !flag) {
      visited[i] = 1;
      ans[cnt] = s[i];
      dfs(cnt + 1);
      visited[i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> s;
  for (int i = 0; i < n; i++)
    if (s[i] == 'A')
      a++;
  if (a < 2) {
    cout << "NO";
    return 0;
  }

  dfs(0);

  return 0;
}