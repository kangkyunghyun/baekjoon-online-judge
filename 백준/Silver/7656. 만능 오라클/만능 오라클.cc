#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  getline(cin, s);
  int idx = 0;
  while (s.find("What is", idx) != string::npos) {
    int w = s.find("What is", idx);
    int c = 1000;
    if (s.find('.', w) != string::npos) {
      int a = s.find('.', w);
      c = min(c, a);
    }
    if (s.find('?', w) != string::npos) {
      int a = s.find('?', w);
      c = min(c, a);
    }
    if (s[c] == '?') {
      string ans = "Forty-two is";
      string tmp = s.substr(w + 7, c - w - 7);
      cout << ans << tmp << ".\n";
    }
    idx = c + 1;
  }
  return 0;
}