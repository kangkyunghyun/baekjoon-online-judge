#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int fail(string pattern) {
  int M = pattern.size();
  vector<int> fail(M, 0);
  for (int i = 1, j = 0; i < M; i++) {
    while (j > 0 && pattern[i] != pattern[j])
      j = fail[j - 1];
    if (pattern[i] == pattern[j])
      fail[i] = ++j;
  }
  if (M % (M - fail[M - 1]) == 0)
    return M / (M - fail[M - 1]);
  else
    return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  while (cin >> s) {
    if (s == ".")
      break;
    cout << fail(s) << '\n';
  }
  return 0;
}