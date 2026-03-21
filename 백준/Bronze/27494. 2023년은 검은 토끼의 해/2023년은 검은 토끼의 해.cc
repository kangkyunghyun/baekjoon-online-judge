#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, ans = 0;
  cin >> n;
  for (int i = 2023; i <= n; i++) {
    string num = to_string(i);
    if (num.find('2', 0) != string::npos) {
      int idx = num.find('2', 0);
      if (num.find('0', idx) != string::npos) {
        idx = num.find('0', idx);
        if (num.find('2', idx) != string::npos) {
          idx = num.find('2', idx);
          if (num.find('3', idx) != string::npos) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}