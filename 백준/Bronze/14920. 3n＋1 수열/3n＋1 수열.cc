#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, ans = 1;
  cin >> n;
  while (n != 1) {
    if (n % 2) {
      n *= 3;
      n += 1;
    } else {
      n /= 2;
    }
    ans++;
  }
  cout << ans;
  return 0;
}