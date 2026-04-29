#include <bits/stdc++.h>
using namespace std;
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    s = '0' + s;
    int last = -1;
    for (int i = s.size() - 1; i > 0; i--) {
      if (s[i] >= '5') {
        if (s[i - 1] == '9') {
          int tmp = i - 1;
          while (s[tmp] == '9') {
            s[tmp] = '0';
            tmp--;
          }
          s[tmp]++;
          last = tmp;
        } else {
          s[i - 1]++;
          s[i] = '0';
          last = i - 1;
        }
      }
    }
    if (last == -1) {
      cout << s.substr(1) << '
';
    } else {
      if (s[0] == '0')
        cout << s.substr(1, last);
      else
        cout << s.substr(0, last + 1);
      for (int i = last + 1; i < s.size(); i++)
        cout << '0';
      cout << '
';
    }
  }
  return 0;
}