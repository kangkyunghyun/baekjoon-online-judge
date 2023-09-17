#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  vector<int> v(5);
  for (int i = 0; i < t; i++)
    cin >> v[i];
  long long ans = 0;
  if (v[0] > v[2])
    ans += (v[0] - v[2]) * 508;
  else
    ans += (v[2] - v[0]) * 108;
  if (v[1] > v[3])
    ans += (v[1] - v[3]) * 212;
  else
    ans += (v[3] - v[1]) * 305;
  if (t > 4)
    ans += v[4] * 707;
  ans *= 4763;
  cout << ans;
}