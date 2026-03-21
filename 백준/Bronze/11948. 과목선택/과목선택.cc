#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0;
  vector<int> v(4), v2(2);
  for (int i = 0; i < 4; i++)
    cin >> v[i];
  for (int i = 0; i < 2; i++)
    cin >> v2[i];
  sort(v.begin(), v.end(), greater<>());
  sort(v2.begin(), v2.end(), greater<>());
  for (int i = 0; i < 3; i++)
    ans += v[i];
  ans += v2[0];
  cout << ans;
  return 0;
}