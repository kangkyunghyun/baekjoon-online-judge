#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    if (s == ".")
      break;
    vector<char> v;
    for (char i : s)
      if (i == '(' || i == ')' || i == '[' || i == ']') {
        if (v.empty()) {
          v.push_back(i);
        } else {
          if (v[v.size() - 1] == '(' && i == ')')
            v.pop_back();
          else if (v[v.size() - 1] == '[' && i == ']')
            v.pop_back();
          else
            v.push_back(i);
        }
      }
    if (v.size() == 0)
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}