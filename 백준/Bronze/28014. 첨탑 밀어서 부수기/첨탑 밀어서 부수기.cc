#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, ans = 1;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = n - 1; i > 0; i--)
    if (v[i] >= v[i - 1])
      ans++;
  cout << ans;
  return 0;
}