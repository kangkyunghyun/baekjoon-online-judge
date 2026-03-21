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
  priority_queue<int> pq;
  for (int i = 1; i <= N; i++)
    if (inDegree[i] == 0)
      pq.push(-i);
  for (int i = 1; i <= N; i++) {
    int node = -pq.top();
    pq.pop();
    ans.push_back(node);
    for (int next : edge[node])
      if (--inDegree[next] == 0)
        pq.push(-next);
  }
  for (int e : ans)
    cout << e << ' ';
  return 0;
}