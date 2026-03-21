#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, cnt = 1, max = 1;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  long long ans = v[0];
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i - 1])
      cnt++;
    else
      cnt = 1;
    if (cnt > max) {
      max = cnt;
      ans = v[i];
    }
  }
  cout << ans;
  return 0;
}