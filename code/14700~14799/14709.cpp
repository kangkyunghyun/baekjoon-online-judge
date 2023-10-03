#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    if (a == 1 && b == 3)
      cnt++;
    else if (a == 1 && b == 4)
      cnt++;
    else if (a == 3 && b == 4)
      cnt++;
  }
  cout << (cnt == 3 && n == 3 ? "Wa-pa-pa-pa-pa-pa-pow!" : "Woof-meow-tweet-squeek");
}