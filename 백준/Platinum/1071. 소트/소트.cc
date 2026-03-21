#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n), ans;
  deque<int> dq;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
    dq.push_back(v[i]);
  while (!dq.empty()) {
    if (dq.back() - dq.front() <= 1) {
      while (!dq.empty()) {
        ans.push_back(dq.back());
        dq.pop_back();
      }
    } else {
      if (ans.size() == 0) {
        ans.push_back(dq.front());
        dq.pop_front();
        continue;
      }
      for (int i = 0; i < n; i++) {
        if (dq[i] - ans.back() != 1) {
          ans.push_back(dq[i]);
          for (int j = 0; j < i; j++) {
            dq.push_back(dq.front());
            dq.pop_front();
          }
          dq.pop_front();
          for (int j = 0; j < i; j++) {
            dq.push_front(dq.back());
            dq.pop_back();
          }
          break;
        }
      }
    }
  }
  for (int i : ans)
    cout << i << ' ';
  cout << '\n';
  return 0;
}