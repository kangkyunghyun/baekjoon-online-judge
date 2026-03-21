#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    stack<char> a, b;
    for (char i : s) {
      if (i == '<') {
        if (!a.empty()) {
          b.push(a.top());
          a.pop();
        }
      } else if (i == '>') {
        if (!b.empty()) {
          a.push(b.top());
          b.pop();
        }
      } else if (i == '-') {
        if (!a.empty()) {
          a.pop();
        }
      } else {
        a.push(i);
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
    cout << '\n';
  }
  return 0;
}