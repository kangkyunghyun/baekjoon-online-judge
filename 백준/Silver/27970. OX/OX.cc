#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long ans = 0, mul = 1, mod = 1e9 + 7;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'O')
      ans += mul;
    ans %= mod;
    mul *= 2;
    mul %= mod;
  }
  cout << ans;
  return 0;
}