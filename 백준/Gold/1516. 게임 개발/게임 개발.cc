#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  vector<int> edge[32001], inDegree(32001, 0), cost(32001), ans;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> cost[i];
    while (1) {
      int x;
      cin >> x;
      if (x == -1)
        break;
      inDegree[i]++;
      edge[x].push_back(i);
    }
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
  for (int i = 1; i <= N; i++)
    cout << ans[i] << '\n';
  return 0;
}