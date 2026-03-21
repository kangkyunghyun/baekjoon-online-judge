#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> visited(100001, -1);

void bfs(int s) {
  queue<int> q;
  q.push(s);
  visited[s] = 0;
  while (!q.empty()) {
    int x = q.front();
    if (x == k)
      return;
    q.pop();
    if (x * 2 <= 100000 && visited[x * 2] == -1) {
      q.push(x * 2);
      visited[x * 2] = visited[x];
    }
    if (x - 1 >= 0 && visited[x - 1] == -1) {
      q.push(x - 1);
      visited[x - 1] = visited[x] + 1;
    }
    if (x + 1 <= 100000 && visited[x + 1] == -1) {
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