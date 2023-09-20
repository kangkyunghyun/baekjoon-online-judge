#include <bits/stdc++.h>
using namespace std;

bool isPal(string s) {
  for (int i = 0; i < s.size() / 2; i++)
    if (s[i] != s[s.size() - i - 1])
      return false;
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int l = 0;
  for (int i = 1; i <= s.size(); i++)
    if (isPal(s.substr(s.size() - i, i)))
      l = max(l, i);
  cout << 2 * s.size() - l;
  return 0;
}