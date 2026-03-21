#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, idx;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] == "?")
      idx = i;
  }
  int m;
  cin >> m;
  string s, ans;
  while (m--) {
    cin >> s;
    if (find(v.begin(), v.end(), s) == v.end()) {
      if (n == 1) {
        ans = s;
        break;
      } else if (idx == 0) {
        string next = v[idx + 1];
        char last = s[s.size() - 1];
        char first = next[0];
        if (last == first) {
          ans = s;
          break;
        }
      } else if (idx == n - 1) {
        string prev = v[idx - 1];
        char first = s[0];
        char last = prev[prev.size() - 1];
        if (first == last) {
          ans = s;
          break;
        }
      } else {
        string next = v[idx + 1];
        string prev = v[idx - 1];
        char nextFirst = next[0];
        char last = s[s.size() - 1];
        char prevLast = prev[prev.size() - 1];
        char first = s[0];
        if (nextFirst == last && prevLast == first) {
          ans = s;
          break;
        }
      }
    }
  }
  cout << s;
  return 0;
}