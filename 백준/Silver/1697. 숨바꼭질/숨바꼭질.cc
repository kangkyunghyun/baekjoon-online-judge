#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> visited(100001, 0);

void bfs(int start) {
  queue<int> q;
  q.push(start);
  if (start == k)
    return;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (x + 1 >= 0 && x + 1 <= 100000)
      if (!visited[x + 1]) {
        q.push(x + 1);
        visited[x + 1] = visited[x] + 1;
      }
    if (x - 1 >= 0 && x - 1 <= 100000)
      if (!visited[x - 1]) {
        q.push(x - 1);
        visited[x - 1] = visited[x] + 1;
      }
    if (x * 2 >= 0 && x * 2 <= 100000)
      if (!visited[x * 2]) {
        q.push(x * 2);
        visited[x * 2] = visited[x] + 1;
      }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> k;
  bfs(n);
  cout << visited[k];
  return 0;
}