#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    string cmd;
    int x;
    cin >> cmd;
    if (cmd == "push") {
      cin >> x;
      v.push_back(x);
    } else if (cmd == "pop") {
      if (v.empty())
        cout << -1 << '\n';
      else {
        cout << v.back() << '\n';
        v.pop_back();
      }
    } else if (cmd == "size") {
      cout << v.size() << '\n';
    } else if (cmd == "empty") {
      cout << v.empty() << '\n';
    } else if (cmd == "top") {
      if (v.empty())
        cout << -1 << '\n';
      else
        cout << v.back() << '\n';
    }
  }
  return 0;
}