#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  deque<char> dq;
  stack<int> s;
  int n;
  cin >> n;
  while (n--) {
    int cmd;
    char c;
    cin >> cmd;
    if (cmd == 1) {
      cin >> c;
      dq.push_back(c);
      s.push(-1);
    } else if (cmd == 2) {
      cin >> c;
      dq.push_front(c);
      s.push(1);
    } else {
      if (!s.empty()) {
        if (s.top() == 1) {
          dq.pop_front();
          s.pop();
        } else if (s.top() == -1) {
          dq.pop_back();
          s.pop();
        }
      }
    }
  }
  if (dq.empty())
    cout << 0;
  else
    for (int i = 0; i < dq.size(); i++)
      cout << dq[i];
  return 0;
}