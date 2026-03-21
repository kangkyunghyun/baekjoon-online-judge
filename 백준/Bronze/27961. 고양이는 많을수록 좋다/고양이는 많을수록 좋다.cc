#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, ans = 0, a = 0;
  cin >> n;
  while (a < n) {
    if (a == 0)
      a++;
    else 
      a *= 2;
    ans++;
  }
  cout << ans;
  return 0;
}