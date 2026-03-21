#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int a, b, ans = 0;
  cin >> a >> b;
  while (a >= 2 && b >= 1) {
    a -= 2;
    b--;
    ans++;
  }
  cout << ans;
  return 0;
}