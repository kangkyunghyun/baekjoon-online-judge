#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, left = 0, right = 0, ans = 0;
  cin >> n >> m;
  deque<int> dq;
  for (int i = 1; i <= n; i++)
    dq.push_back(i);
  while (m--) {
    int x;
    cin >> x;
    for (int i = 0; i < dq.size(); i++) {
      if (dq[i] == x) {
        left = i;
        right = dq.size() - i;
      }
    }
    if (left <= right) {
      while (dq.front() != x) {
        dq.push_back(dq.front());
        dq.pop_front();
        ans++;
      }
      dq.pop_front();
    } else {
      while (dq.front() != x) {
        dq.push_front(dq.back());
        dq.pop_back();
        ans++;
      }
      dq.pop_front();
    }
  }
  cout << ans << '\n';
  return 0;
}