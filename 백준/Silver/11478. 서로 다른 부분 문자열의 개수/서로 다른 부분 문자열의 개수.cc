#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  map<string, bool> m;
  int length = 1, cnt = 0;
  for (int i = s.length(); i > 0; i--) {
    int index = 0;
    for (int j = 0; j < i; j++) {
      string str = s.substr(index, length);
      m.insert(make_pair(str, true));
      index++;
    }
    length++;
  }
  for (auto i : m)
    cnt++;
  cout << cnt << '\n';
  return 0;
}