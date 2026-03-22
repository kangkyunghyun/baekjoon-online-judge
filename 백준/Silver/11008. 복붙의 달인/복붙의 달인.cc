#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s, p;
    cin >> s >> p;
    int cnt = 0;
    while (s.find(p) != string::npos) {
      cnt++;
      int index = s.find(p);
      for (int k = index; k < index + p.length(); k++)
        s[k] = '*';
    }
    cout << s.length() - cnt * p.length() + cnt << '\n';
  }
  return 0;
}