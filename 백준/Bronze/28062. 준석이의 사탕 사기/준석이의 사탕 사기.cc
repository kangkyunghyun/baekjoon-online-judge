#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n), odd;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] % 2)
      odd.push_back(v[i]);
  }
  if (odd.size() == 1 && n == 1) {
    cout << 0;
  } else if (odd.size() % 2) {
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (v[i] % 2 == 0)
        ans += v[i];
    sort(odd.begin(), odd.end(), greater<>());
    for (int i = 0; i < odd.size() - 1; i++)
      ans += odd[i];
    cout << ans;
  } else {
    cout << accumulate(v.begin(), v.end(), 0);
  }
  return 0;
}