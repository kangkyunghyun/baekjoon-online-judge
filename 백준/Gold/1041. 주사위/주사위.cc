#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, a, b, c, d, e, f, ans = 0;
  cin >> n >> a >> b >> c >> d >> e >> f;
  if (n == 1) {
    vector<long long> v{a, b, c, d, e, f};
    sort(v.begin(), v.end());
    for (int i = 0; i < 5; i++)
      ans += v[i];
  } else {
    vector<long long> v{a, b, c, d, e, f};
    long long one_face = *min_element(v.begin(), v.end());
    v = {a + b, a + c, a + d, a + e, b + c, b + d, b + f, c + e, c + f, d + e, d + f, e + f};
    long long two_face = *min_element(v.begin(), v.end());
    v = {a + b + c, a + b + d, a + d + e, a + c + e, b + c + f, b + d + f, c + e + f, d + e + f};
    long long three_face = *min_element(v.begin(), v.end());
    ans += three_face * 4 + two_face * ((n - 2) * 4 + (n - 1) * 4) + one_face * ((n - 2) * (n - 2) + (n - 2) * (n - 1) * 4);
  }
  cout << ans << '\n';
  return 0;
}