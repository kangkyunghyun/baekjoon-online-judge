#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int l;
  string s;
  cin >> l >> s;
  int fail[1000001] = {0};
  int M = s.size();
  for (int i = 1, j = 0; i < M; i++) {
    while (j > 0 && s[i] != s[j])
      j = fail[j - 1];
    if (s[i] == s[j])
      fail[i] = ++j;
  }
  cout << l - fail[l - 1];
  return 0;
}