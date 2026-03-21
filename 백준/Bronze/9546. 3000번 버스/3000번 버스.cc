#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int k;
    double ans = 0;
    cin >> k;
    while (k--) {
      ans += 0.5;
      ans *= 2;
    }
    cout << (int)ans << '\n';
  }
  return 0;
}