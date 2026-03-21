#include <bits/stdc++.h>
using namespace std;

int n, s, ans = 0, arr[21];

void dfs(int sum, int idx) {
  if (idx == n)
    return;
  if (sum + arr[idx] == s)
    ans++;
  dfs(sum + arr[idx], idx + 1);
  dfs(sum, idx + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  dfs(0, 0);
  cout << ans;
  return 0;
}