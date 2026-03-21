#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  stack<long long> s;
  string str;
  while (cin >> str) {
    if (str == "[") {
      s.push(0);
    } else if (isdigit(str[0])) {
      s.push(8);
    } else if (str == "]") {
      long long tmp = 0;
      while (s.top() != 0) {
        tmp += s.top();
        s.pop();
      }
      s.pop();
      s.push(tmp + 8);
    } else {
      s.push(str.size() + 12);
    }
  }
  cout << s.top();
  return 0;
}