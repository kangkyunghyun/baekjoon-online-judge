#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> d(n);
  for (int i = 0; i < n; i++)
    cin >> d[i];
  sort(d.begin(), d.end(), greater<>());
  int ans = c / a;
  int price = a, cal = c;
  for (int i = 0; i < n; i++) {
    price += b;
    cal += d[i];
    if (ans < cal / price)
      ans = cal / price;
  }
  cout << ans << '\n';
  return 0;
}