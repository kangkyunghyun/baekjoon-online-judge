#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int h, w, n;
    cin >> h >> w >> n;
    int h1 = n % h;
    int w1 = n / h;
    if (h1 > 0)
      w1++;
    else
      h1 = h;
    cout << h1 * 100 + w1 << '\n';
  }
  return 0;
}