#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  cin.tie(0)->sync_with_stdio(0);
  while (1) {
    ll a, b;
    cin >> a >> b;
    if (a + b == 0)
      break;
    vector<ll> v;
    ll tmp = a;
    while (tmp != 1) {
      v.push_back(tmp);
      if (tmp % 2)
        tmp = 3 * tmp + 1;
      else
        tmp /= 2;
    }
    v.push_back(1);
    tmp = b;
    ll cnt = 0;
    bool flag = 0;
    while (tmp != 1) {
      auto it = find(v.begin(), v.end(), tmp);
      if (it != v.end()) {
        cout << a << " needs " << it - v.begin() << " steps, " << b << " needs " << cnt << " steps, they meet at " << tmp << '\n';
        flag = 1;
        break;
      }
      if (tmp % 2)
        tmp = 3 * tmp + 1;
      else
        tmp /= 2;
      cnt++;
    }
    if (!flag) {
      cout << a << " needs " << v.size() - 1 << " steps, " << b << " needs " << cnt << " steps, they meet at " << 1 << '\n';
    }
  }
  return 0;
}