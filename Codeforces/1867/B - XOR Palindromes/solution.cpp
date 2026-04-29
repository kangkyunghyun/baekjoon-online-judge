#include <bits/stdc++.h>
using namespace std;
 
bool isPal(string s) {
  for (int i = 0; i < s.size() / 2; i++)
    if (s[i] != s[s.size() - 1 - i])
      return false;
  return true;
}
 
int cntErr(string s) {
  int cnt = 0;
  for (int i = 0; i < s.size() / 2; i++)
    if (s[i] != s[s.size() - 1 - i])
      cnt++;
  return cnt;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s, ans = "";
    cin >> n >> s;
    int err = cntErr(s);
    for (int i = 0; i <= n; i++) {
      int x = err - i;
      if (x == 0) {
        ans += '1';
      } else if (x > 0) {
        ans += '0';
      } else if (x < 0) {
        int left = -x;
        int half = n / 2;
        int available = half - err;
        if (left >= available * 2) {
          left -= 2 * available;
          if (left == 0)
            ans += '1';
          else if (n % 2 == 1 && left == 1) {
            ans += '1';
          } else {
            ans += '0';
          }
        } else {
          if (n % 2 == left % 2) {
            ans += '1';
          } else if (left % 2 == 0) {
            ans += '1';
          } else {
            ans += '0';
          }
        }
 
        // int a = left % 2, b = n % 2;
        // if (b) {
        //   ans += '1';
        // } else {
        //   if (a == b)
        //     ans += '1';
        //   else
        //     ans += '0';
        // }
      }
    }
    cout << ans << '
';
  }
  return 0;
}