#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, flag = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
      int index = 0, tmp = (i + 1) % 2;
      while (s.find(s[i], index) != string::npos) {
        int idx = s.find(s[i], index) + 1;
        if (idx % 2 != tmp) {
          flag = 1;
          break;
        }
        index = idx;
      }
    }
    if (flag)
      cout << "NO
";
    else
      cout << "YES
";
  }
  return 0;
}