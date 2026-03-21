#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, ans = 0, cnt = 0;
  cin >> n >> k;
  priority_queue<int> pq[12];
  for (int i = 0; i < n; i++) {
    int p, w;
    cin >> p >> w;
    pq[p].push(w);
  }
  for (int i = 0; i < k; i++) {
    for (int j = 1; j <= 11; j++) {
      if (pq[j].empty())
        continue;
      int x = pq[j].top();
      pq[j].pop();
      pq[j].push(max(0, x - 1));
    }
  }
  for (int i = 1; i <= 11; i++) {
    if (pq[i].empty())
      continue;
    ans += pq[i].top();
  }
  cout << ans;
  return 0;
}