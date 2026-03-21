#include <bits/stdc++.h>
using namespace std;

int n, cnt;
vector<int> v(100001, 0), visited(100001, 0), result;

void dfs(int x) {
  visited[x] = 1;
  result.push_back(x);
  if (visited[v[x]]) {
    if (find(result.begin(), result.end(), v[x]) != result.end())
      for (auto iter = find(result.begin(), result.end(), v[x]); iter != result.end(); iter++)
        cnt++;
  } else {
    dfs(v[x]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
      visited[i] = 0;
    }
    for (int i = 1; i <= n; i++)
      if (!visited[i]) {
        result.clear();
        dfs(i);
      }
    cout << n - cnt << '\n';
  }
  return 0;
}