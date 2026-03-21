#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<pair<char, int>> v;
  int ans = 0;
  for (char c : s) {
    if (c == ')') {
      int size = 0;
      while (v.back().first != '(') {
        size += v.back().second;
        v.pop_back();
      }
      v.pop_back();
      int cnt = v.back().first - '0';
      v.back().second = cnt * size;
    } else {
      v.push_back(make_pair(c, 1));
    }
  }
  while (!v.empty()) {
    ans += v.back().second;
    v.pop_back();
  }
  cout << ans;
  return 0;
}