#include <bits/stdc++.h>
using namespace std;

int l, c;
vector<char> v(15, '~'), ans(15, ' ');
vector<int> visited(15, 0);

void dfs(int cnt) {
  if (cnt == l) {
    int tmp = 0;
    for (int i = 0; i < l; i++)
      if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u')
        tmp++;
    if (tmp >= 1 && l - tmp >= 2) {
      for (int i = 0; i < l; i++)
        cout << ans[i];
      cout << '\n';
    }
    return;
  }
  for (int i = 0; i < c; i++) {
    if (!visited[i] && ans[cnt - 1] < v[i]) {
      visited[i] = 1;
      ans[cnt] = v[i];
      dfs(cnt + 1);
      visited[i] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> l >> c;
  for (int i = 0; i < c; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  dfs(0);
  return 0;
}