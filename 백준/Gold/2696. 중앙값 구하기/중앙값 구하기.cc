#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int m, cnt = 0;
    cin >> m;
    cout << (m + 1) / 2 << '\n';
    priority_queue<int> pq;
    while (m--) {
      int x;
      cin >> x;
      cnt++;
      pq.push(x);
      if (cnt % 2) {
        int idx = pq.size() / 2;
        vector<int> tmp;
        for (int i = 0; i < idx; i++) {
          tmp.push_back(pq.top());
          pq.pop();
        }
        cout << pq.top() << ' ';
        for (int i = 0; i < idx; i++)
          pq.push(tmp[i]);
      }
    }
    cout << '\n';
  }
  return 0;
}