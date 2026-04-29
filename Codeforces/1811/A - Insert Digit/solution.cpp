#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int n, d, flag = 0;
    string s;
    cin >> n >> d >> s;
    for (int i = 0; i < n; i++) {
      int num = s[i] - '0';
      if (num >= d) {
        cout << num;
      } else {
        if (flag) {
          cout << num;
        } else {
          cout << d << num;
          flag = 1;
        }
      }
    }
    if (!flag)
      cout << d;
    cout << '
';
  }
  return 0;
}