#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  int cnt = 0;
  while (cin >> s)
    if (s == "<br>") {
      cout << '\n';
      cnt = 0;
    } else if (s == "<hr>") {
      if (cnt)
        cout << '\n';
      cout << "--------------------------------------------------------------------------------\n";
      cnt = 0;
    } else {
      if (!cnt) {
        cout << s;
        cnt += s.size();
      } else if (cnt + s.size() + 1 <= 80) {
        cout << ' ' << s;
        cnt += s.size() + 1;
      } else {
        cout << '\n' << s;
        cnt = s.length();
      }
    }
  return 0;
}