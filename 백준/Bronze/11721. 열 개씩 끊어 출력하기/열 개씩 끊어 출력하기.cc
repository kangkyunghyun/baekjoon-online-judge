#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  for (int i = 1; i <= s.size(); i++) {
    cout << s[i - 1];
    if (!(i % 10))
      cout << '\n';
  }
  return 0;
}