#include <bits/stdc++.h>
using namespace std;

int n, k, cnt = 0, m = 2147483647;
vector<int> visited(100001, 0);

void bfs(int xx) {
  queue<pair<int, int>> q;
  q.push({xx, 0});
  visited[xx] = 1;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    visited[x] = 1;
    q.pop();
    if (m < y)
      break;
    if (x == k) {
      m = y;
      cnt++;
    }
    if (x + 1 >= 0 && x + 1 <= 100000)
      if (!visited[x + 1])
        q.push({x + 1, y + 1});
    if (x - 1 >= 0 && x - 1 <= 100000)
      if (!visited[x - 1])
        q.push({x - 1, y + 1});
    if (x * 2 >= 0 && x * 2 <= 100000)
      if (!visited[x * 2])
        q.push({x * 2, y + 1});
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> k;
  bfs(n);
  cout << m << '\n'
       << cnt;
  return 0;
}