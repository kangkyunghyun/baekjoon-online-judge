#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll t;
  cin >> t;
  while (t--) {
    ll n, k, x;
    cin >> n >> k >> x;
    if (k * (k + 1) / 2 > x || n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2 < x)
      cout << "NO
";
    else
      cout << "YES
";
  }
  return 0;
}