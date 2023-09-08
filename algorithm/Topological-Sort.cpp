#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  vector<int> edge[32001], inDegree(32001, 0), ans;
  cin >> N >> M;
  while (M--) {
    int u, v;
    cin >> u >> v;
    inDegree[v]++;
    edge[u].push_back(v);
  }
  queue<int> q;
  for (int i = 1; i <= N; i++)
    if (inDegree[i] == 0)
      q.push(i);
  for (int i = 1; i <= N; i++) {
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (int next : edge[node])
      if (--inDegree[next] == 0)
        q.push(next);
  }
  for (int e : ans)
    cout << e << ' ';
  return 0;
}