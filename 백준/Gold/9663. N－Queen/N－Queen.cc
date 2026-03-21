#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> graph(15, 0);

int check(int row) {
  for (int i = 0; i < row; i++)
    if (graph[i] == graph[row] || abs(row - i) == abs(graph[row] - graph[i]))
      return 0;
  return 1;
}

void dfs(int row) {
  if (row == n) {
    ans++;
    return;
  }
  for (int col = 0; col < n; col++) {
    graph[row] = col;
    if (check(row))
      dfs(row + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  dfs(0);
  cout << ans;
  return 0;
}