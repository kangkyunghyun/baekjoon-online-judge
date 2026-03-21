#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m = 0;
  cin >> n;
  priority_queue<int> q;
  while (n--) {
    int x;
    cin >> x;
    m = max(m, x);
    q.push(-x);
  }
  int mx = m;
  int ans = mx + q.top();
  while (-q.top() < m) {
    int x = -q.top();
    q.pop();
    ans = min(ans, mx - x);
    mx = max(mx, 2 * x);
    q.push(-2 * x);
  }
  cout << min(mx + q.top(), ans);
  return 0;
}