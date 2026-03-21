#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int N, K, W;
    vector<int> edge[1001], inDegree(1001, 0), cost(1001), ans;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
      cin >> cost[i];
    while (K--) {
      int u, v;
      cin >> u >> v;
      inDegree[v]++;
      edge[u].push_back(v);
    }
    queue<int> q;
    for (int i = 1; i <= N; i++)
      if (inDegree[i] == 0)
        q.push(i);
    ans = cost;
    for (int i = 1; i <= N; i++) {
      int node = q.front();
      q.pop();
      for (int next : edge[node]) {
        ans[next] = max(ans[next], ans[node] + cost[next]);
        if (--inDegree[next] == 0)
          q.push(next);
      }
    }
    cin >> W;
    cout << ans[W] << '\n';
  }
  return 0;
}