#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, k;
vector<int> visited(100001, INF);

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = 0;
  while (!q.empty()) {
    int x = q.front();
    if (x == k)
      return;
    q.pop();
    if (x * 2 >= 0 && x * 2 <= 100000)
      if (visited[x * 2] == INF && visited[x * 2] > visited[x]) {
        q.push(x * 2);
        visited[x * 2] = visited[x];
      }
    if (x - 1 >= 0 && x - 1 <= 100000)
      if (visited[x - 1] == INF && visited[x - 1] > visited[x] + 1) {
        q.push(x - 1);
        visited[x - 1] = visited[x] + 1;
      }
    if (x + 1 >= 0 && x + 1 <= 100000)
      if (visited[x + 1] == INF && visited[x + 1] > visited[x] + 1) {
        q.push(x + 1);
        visited[x + 1] = visited[x] + 1;
      }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  bfs(n);
  cout << visited[k] << '\n';
  return 0;
}