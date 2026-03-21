#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cin.ignore();
  string s;
  while (n--) {
    string s, tmp = "";
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        cout << tmp << ' ';
        tmp = "";
        continue;
      }
      tmp = s[i] + tmp;
    }
    cout << tmp << '\n';
  }
  return 0;
}