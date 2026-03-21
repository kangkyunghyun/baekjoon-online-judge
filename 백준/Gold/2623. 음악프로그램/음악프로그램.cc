#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M;
  vector<int> edge[1001], inDegree(1001, 0), ans;
  cin >> N >> M;
  while (M--) {
    int K, u, v;
    cin >> K;
    if (K == 0)
      continue;
    cin >> u;
    while (--K) {
      cin >> v;
      inDegree[v]++;
      edge[u].push_back(v);
      u = v;
    }
  }
  queue<int> q;
  for (int i = 1; i <= N; i++)
    if (inDegree[i] == 0)
      q.push(i);
  for (int i = 1; i <= N; i++) {
    if (q.empty()) {
      cout << 0;
      return 0;
    }
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (int next : edge[node])
      if (--inDegree[next] == 0)
        q.push(next);
  }
  for (int e : ans)
    cout << e << '\n';
  return 0;
}