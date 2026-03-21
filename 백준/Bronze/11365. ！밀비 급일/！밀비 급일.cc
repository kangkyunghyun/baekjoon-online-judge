#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  while (getline(cin, s)) {
    if (s == "END")
      break;
    for (int i = s.length() - 1; i >= 0; i--)
      cout << s[i];
    cout << '\n';
  }
  return 0;
}