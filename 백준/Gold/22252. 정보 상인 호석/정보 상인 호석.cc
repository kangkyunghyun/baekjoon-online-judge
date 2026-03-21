#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int q;
  long long ans = 0;
  cin >> q;
  map<string, priority_queue<int>> m;
  while (q--) {
    int cmd;
    string name;
    cin >> cmd >> name;
    if (cmd == 1) {
      int n;
      cin >> n;
      while (n--) {
        int x;
        cin >> x;
        m[name].push(x);
      }
    } else if (cmd == 2) {
      int n;
      cin >> n;
      while (n-- && !m[name].empty()) {
        ans += m[name].top();
        m[name].pop();
      }
    }
  }
  cout << ans << '\n';
  return 0;
}