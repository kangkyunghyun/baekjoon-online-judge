#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, mul = 31, MOD = 1234567891;
  cin >> n;
  string s;
  cin >> s;
  long long ans = 0;
  long long R = 1;
  for (int i = 0; i < n; i++) {
    ans = (ans + ((int)s[i] - 96) * R) % MOD;
    R = (R * mul) % MOD;
  }
  cout << ans;
  return 0;
}