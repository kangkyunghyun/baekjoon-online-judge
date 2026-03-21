#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    string s;
    cin >> s;
    if (s == "0")
      break;
    int cnt = 0;
    for (int i = 0; i < floor((float)s.size() / 2 + 0.5); i++) {
      if (s[i] != s[s.size() - i - 1]) {
        cout << "no\n";
        break;
      } else {
        cnt++;
      }
    }
    if (cnt == floor((float)s.size() / 2 + 0.5))
      cout << "yes\n";
  }
  return 0;
}