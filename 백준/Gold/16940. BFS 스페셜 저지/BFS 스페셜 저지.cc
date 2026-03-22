#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
vector<int> graph[100001], visited(100001, 0), v(100001, 0), order(100001, 0), way(100001, 0);

bool cmp(int a, int b) {
  return order[a] < order[b];
}

void bfs(int s) {
  queue<int> q;
  q.push(s);
  visited[s] = 1;
  way[cnt++] = s;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int y : graph[x])
      if (!visited[y]) {
        q.push(y);
        visited[y] = 1;
        way[cnt++] = y;
      }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    order[v[i]] = i;
  }
  for (int i = 1; i <= n; i++)
    sort(graph[i].begin(), graph[i].end(), cmp);
  bfs(1);
  cout << (way == v ? 1 : 0) << '\n';
  return 0;
}