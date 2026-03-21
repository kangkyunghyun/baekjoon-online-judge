#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s, ans = "";
  cin >> s;
  int index = 0, hyphen = s.find('-', index);
  ans += s[0];
  while (hyphen != string::npos) {
    index = hyphen + 1;
    ans += s[index];
    hyphen = s.find('-', index);
  }
  cout << ans;
  return 0;
}