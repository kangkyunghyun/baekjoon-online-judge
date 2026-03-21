#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      q.push(make_pair(j, x));
      pq.push(x);
    }
    int cnt = 0;
    while (!q.empty()) {
      if (q.front().first == m && q.front().second == pq.top()) {
        q.pop();
        pq.pop();
        cnt++;
        cout << cnt << '\n';
        break;
      } else if (q.front().second == pq.top()) {
        q.pop();
        pq.pop();
        cnt++;
      } else {
        q.push(q.front());
        q.pop();
      }
    }
  }
  return 0;
}