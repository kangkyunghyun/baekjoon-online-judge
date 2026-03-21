#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    multiset<int> ms;
    char cmd;
    int n, k;
    cin >> k;
    while (k--) {
      cin >> cmd >> n;
      if (cmd == 'I') {
        ms.insert(n);
      } else {
        if (!ms.empty() && n == -1) {
          ms.erase(ms.begin());
        } else if (!ms.empty() && n == 1) {
          auto iter = ms.end();
          iter--;
          ms.erase(iter);
        }
      }
    }
    if (ms.empty()) {
      cout << "EMPTY\n";
    } else {
      auto iter = ms.end();
      iter--;
      cout << *iter << ' ' << *ms.begin() << '\n';
    }
  }
  return 0;
}