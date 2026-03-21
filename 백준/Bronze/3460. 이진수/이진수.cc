#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s = "";
    int max = n;
    for (int i = max; i >= 0; i--) {
      if (pow(2, i) <= max) {
        if (pow(2, i) <= n) {
          n -= pow(2, i);
          s.push_back('1');
        } else {
          s.push_back('0');
        }
      }
    }
    for (int i = s.size() - 1; i >= 0; i--)
      if (s[i] == '1')
        cout << s.size() - 1 - i << ' ';
  }
  return 0;
}