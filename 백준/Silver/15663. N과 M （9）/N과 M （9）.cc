#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> tmp(8, 0), v, visited(10001, 0), arr(10001, 0);
vector<vector<int>> ans;

void dfs(int cnt) {
  if (cnt == m) {
    ans.push_back(tmp);
    return;
  }
  for (int i = 0; i < n; i++)
    if (visited[v[i]] < arr[v[i]]) {
      visited[v[i]]++;
      tmp[cnt] = v[i];
      dfs(cnt + 1);
      visited[v[i]]--;
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
    arr[x]++;
  }
  sort(v.begin(), v.end());
  dfs(0);
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  for (auto i : ans) {
    for (int j = 0; j < m; j++)
      cout << i[j] << ' ';
    cout << '\n';
  }
  return 0;
}