#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int small = a > b ? b : a;
    int big = a > b ? a : b;
    int cnt = 0;
    while (small < big) {
      cnt++;
      big -= c;
      small += c;
    }
    cout << cnt << '
';
  }
  return 0;
}