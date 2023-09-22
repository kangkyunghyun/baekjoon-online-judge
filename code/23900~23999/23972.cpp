#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll k, n;
  cin >> k >> n;
  if (n == 1) {
    cout << -1;
    return 0;
  }
  if (k * n % (n - 1))
    cout << k * n / (n - 1) + 1;
  else
    cout << k * n / (n - 1);
  return 0;
}