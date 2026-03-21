#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  set<string> s;
  for (int i = 0; i < 4; i++) {
    string tmp;
    cin >> tmp;
    s.insert(tmp);
  }
  for (auto i = s.begin(); i != s.end(); i++)
    for (auto j = s.begin(); j != s.end(); j++)
      cout << *i << ' ' << *j << '\n';
  return 0;
}