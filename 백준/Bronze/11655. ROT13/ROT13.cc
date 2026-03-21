#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  getline(cin, s);
  for (char i : s) {
    if (i >= 'a' && i <= 'z') {
      char a = i - 'a';
      a += 13;
      a %= 26;
      a += 'a';
      cout << a;
    } else if (i >= 'A' && i <= 'Z') {
      char a = i - 'A';
      a += 13;
      a %= 26;
      a += 'A';
      cout << a;
    } else {
      cout << i;
    }
  }
  return 0;
}