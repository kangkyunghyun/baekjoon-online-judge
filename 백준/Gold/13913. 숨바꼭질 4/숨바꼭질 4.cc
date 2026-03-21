#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> visited(100001, 0), bef(100001, -1);

void bfs(int start) {
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int x = q.front();
    if (x == k)
      break;
    q.pop();
    if (x + 1 >= 0 && x + 1 <= 100000)
      if (!visited[x + 1]) {
        q.push(x + 1);
        visited[x + 1] = visited[x] + 1;
        bef[x + 1] = x;
      }
    if (x - 1 >= 0 && x - 1 <= 100000)
      if (!visited[x - 1]) {
        q.push(x - 1);
        visited[x - 1] = visited[x] + 1;
        bef[x - 1] = x;
      }
    if (x * 2 >= 0 && x * 2 <= 100000)
      if (!visited[x * 2]) {
        q.push(x * 2);
        visited[x * 2] = visited[x] + 1;
        bef[x * 2] = x;
      }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  bfs(n);
  cout << visited[k] << '\n';
  int tmp = k;
  vector<int> ans;
  while (tmp != n) {
    ans.push_back(tmp);
    tmp = bef[tmp];
  }
  ans.push_back(tmp);
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}