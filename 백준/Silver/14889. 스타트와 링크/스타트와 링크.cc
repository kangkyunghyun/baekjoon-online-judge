#include <bits/stdc++.h>
using namespace std;

int n, arr[21][21], ans = INT_MAX, visited[21];

void dfs(int depth, int num) {
  if (depth == n / 2) {
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (visited[i] && visited[j])
          a += arr[i][j];
        else if (!visited[i] && !visited[j])
          b += arr[i][j];
    ans = min(ans, abs(a - b));
  } else
    for (int i = num; i <= n; i++)
      if (!visited[i]) {
        visited[i] = 1;
        dfs(depth + 1, i + 1);
        visited[i] = 0;
      }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> arr[i][j];
  dfs(0, 1);
  cout << ans;
  return 0;
}