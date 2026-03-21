#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, p, ans;
  cin >> n >> p;
  if (n >= 20) {
    ans = p * 0.75;
    if (ans > p - 2000)
      ans = p - 2000;
  } else if (n >= 15) {
    ans = p - 2000;
    if (ans > p * 0.9)
      ans = p * 0.9;
  } else if (n >= 10) {
    ans = p * 0.9;
    if (ans > p - 500)
      ans = p - 500;
  } else if (n >= 5) {
    ans = p - 500;
  } else {
    ans = p;
  }
  ans = max(ans, 0);
  cout << ans;
  return 0;
}