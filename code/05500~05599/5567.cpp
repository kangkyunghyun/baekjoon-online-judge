#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> edge[501], visited(501, -1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  queue<int> q;
  visited[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    if (visited[curr] == 2)
      break;
    for (int next : edge[curr]) {
      if (visited[next] == -1) {
        visited[next] = visited[curr] + 1;
        q.push(next);
        ans++;
      }
    }
  }
  cout << ans;
}