#include <bits/stdc++.h>
using namespace std;

int isPal(string s, int err) {
  int left = 0, right = s.size() - 1;
  while (left < right) {
    if (s[left] != s[right]) {
      if (err == 0) {
        int len = right - left;
        if (isPal(s.substr(left, len), err + 1) == 0 || isPal(s.substr(left + 1, len), err + 1) == 0)
          return 1;
        else
          return 2;
      } else {
        return 2;
      }
    }
    left++;
    right--;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << isPal(s, 0) << '\n';
  }
  return 0;
}