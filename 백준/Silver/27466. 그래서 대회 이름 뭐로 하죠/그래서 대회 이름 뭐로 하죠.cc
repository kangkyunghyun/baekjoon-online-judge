#include <bits/stdc++.h>
using namespace std;

int n, m, flag = 0;
string s;
vector<int> visited(300001, 0);
vector<char> ans(300001);

void dfs(int cnt, int before) {
  if (cnt == m) {
    if (ans[m - 2] == 'A' && ans[m - 3] == 'A' && (ans[m - 1] != 'A' && ans[m - 1] != 'E' && ans[m - 1] != 'I' && ans[m - 1] != 'O' && ans[m - 1] != 'U')) {
      cout << "YES\n";
      for (int i = 0; i < m; i++)
        cout << ans[i];
      cout << '\n';
      flag = 1;
    }
    ans.clear();
    return;
  }
  for (int i = 0; i < n; i++) {
    if (i > before && !visited[i] && !flag) {
      visited[i] = 1;
      ans[cnt] = s[i];
      dfs(cnt + 1, i);
      visited[i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> s;
  vector<int> a;
  for (int i = 0; i < n; i++)
    if (s[i] == 'A')
      a.push_back(i);
  if (a.size() < 2) {
    cout << "NO\n";
    return 0;
  }
  if (n == m) {
    if (s[m - 2] == 'A' && s[m - 3] == 'A' && (s[m - 1] != 'A' && s[m - 1] != 'E' && s[m - 1] != 'I' && s[m - 1] != 'O' && s[m - 1] != 'U')) {
      cout << "YES\n";
      cout << s << '\n';
    } else {
      cout << "NO\n";
    }
    return 0;
  }
  int f = 0;
  for (int i = 0; i < a.size() - 1; i++) {
    if (n - a[i] - 1 <= m - 3) {
      cout << "NO\n";
      return 0;
    }
  }
  dfs(0, -1);
  return 0;
}