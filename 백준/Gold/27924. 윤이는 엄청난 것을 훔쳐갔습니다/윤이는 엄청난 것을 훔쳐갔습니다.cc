#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> edges[200001];
int av[200001], bv[200001], cv[200001];

void bfs(int x, int visited[]) {
  queue<int> q;
  q.push(x);
  visited[x] = 1;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int next : edges[curr]) {
      if (!visited[next]) {
        q.push(next);
        visited[next] = visited[curr] + 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  int a, b, c;
  cin >> a >> b >> c;
  bfs(a, av);
  bfs(b, bv);
  bfs(c, cv);
  vector<int> leaf;
  for (int i = 1; i <= n; i++)
    if (edges[i].size() == 1)
      leaf.push_back(i);
  for (int i : leaf) {
    if (av[i] < bv[i] && av[i] < cv[i]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}