#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end(), greater<>());
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (a[i] >= a[k - 1] && a[i])
      ans++;
  cout << ans;
}