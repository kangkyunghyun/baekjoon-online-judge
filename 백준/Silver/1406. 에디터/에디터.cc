#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  int m;
  cin >> s >> m;
  stack<char> a, b;
  for (char i : s)
    a.push(i);
  while (m--) {
    char c;
    cin >> c;
    if (c == 'L') {
      if (!a.empty()) {
        b.push(a.top());
        a.pop();
      }
    } else if (c == 'D') {
      if (!b.empty()) {
        a.push(b.top());
        b.pop();
      }
    } else if (c == 'B') {
      if (!a.empty()) {
        a.pop();
      }
    } else {
      cin >> c;
      a.push(c);
    }
  }
  while (!a.empty()) {
    b.push(a.top());
    a.pop();
  }
  while (!b.empty()) {
    cout << b.top();
    b.pop();
  }
  return 0;
}