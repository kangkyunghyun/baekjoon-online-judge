#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0;
  while (1) {
    int n;
    cin >> n;
    if (n == -1)
      break;
    ans += n;
  }
  cout << ans;
  return 0;
}