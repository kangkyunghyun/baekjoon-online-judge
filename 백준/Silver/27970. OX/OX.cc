#include <bits/stdc++.h>
using namespace std;

long long power(long long x, long long y) {
  if (y == 0)
    return 1;
  long long result = power(x, y / 2);
  if (y % 2 == 0)
    return result % 1000000007 * result % 1000000007;
  else
    return x * result % 1000000007 * result % 1000000007;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long ans = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == 'O')
      ans = ((ans % 1000000007) + (power(2, i) % 1000000007)) % 1000000007;
  cout << ans;
  return 0;
}