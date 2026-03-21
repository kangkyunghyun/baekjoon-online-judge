#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<char> v;
  for (char c : s) {
    if (v.empty()) {
      v.push_back(c);
    } else {
      if (c == ')' && v.back() == '(')
        v.pop_back();
      else
        v.push_back(c);
    }
  }
  cout << v.size();
  return 0;
}