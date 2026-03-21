#include <bits/stdc++.h>
using namespace std;

int getPriority(char c) {
  switch (c) {
  case '*':
  case '/':
    return 3;
  case '+':
  case '-':
    return 2;
  case '(':
    return 1;
  default:
    return -1;
  }
}

int main() {
  string s, ans = "";
  cin >> s;
  vector<char> v;
  for (char c : s) {
    switch (c) {
    case '(':
      v.push_back(c);
      break;
    case ')':
      while (1) {
        if (v.back() == '(') {
          v.pop_back();
          break;
        }
        ans += v.back();
        v.pop_back();
      }
      break;
    case '+':
    case '-':
    case '*':
    case '/':
      while (!v.empty() && getPriority(c) <= getPriority(v.back())) {
        ans += v.back();
        v.pop_back();
      }
      v.push_back(c);
      break;
    default:
      ans += c;
      break;
    }
  }
  while (!v.empty()) {
    ans += v.back();
    v.pop_back();
  }
  cout << ans << '\n';
  return 0;
}