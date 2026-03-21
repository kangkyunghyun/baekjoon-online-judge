#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (!b)
    return a;
  return gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string p;
  cin >> p;
  long long n = 0, m = 1;
  for (int i = p.size() - 1; i >= 0; i--) {
    if (p[i] == '.')
      continue;
    n += (p[i] - '0') * m;
    m *= 10;
  }
  m /= 10;
  long long g = gcd(n, m);
  n /= g;
  m /= g;
  vector<long long> ans(7, 0);
  long long a = n / m;
  long long b = n % m;
  ans[a] = m - b;
  ans[a + 1] = b;
  for (int i = 1; i <= 5; i++)
    cout << ans[i] << ' ';
  return 0;
}