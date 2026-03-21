#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cnt = 0, ans = 0;
  cin >> n;
  while (cnt != n) {
    ans++;
    int temp = ans;
    while (temp != 0) {
      if (temp % 1000 == 666) {
        cnt++;
        break;
      } else {
        temp /= 10;
      }
    }
  }
  cout << ans;
  return 0;
}