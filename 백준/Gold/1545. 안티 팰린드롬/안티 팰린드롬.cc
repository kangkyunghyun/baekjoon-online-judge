#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int size = s.size();
  sort(s.begin(), s.end());
  int left, right;
  if (size % 2 == 0) {
    left = size / 2 - 1;
    right = size / 2;
  } else {
    left = size / 2 - 1;
    right = size / 2 + 1;
  }
  while (left >= 0) {
    if (s[left] == s[right]) {
      int idx = right;
      while (s[idx] == s[right]) {
        idx++;
        if (idx == size) {
          cout << "-1\n";
          return 0;
        }
      }
      char tmp = s[right];
      s[right] = s[idx];
      s[idx] = tmp;
    }
    left--;
    right++;
  }
  cout << s << '\n';
  return 0;
}