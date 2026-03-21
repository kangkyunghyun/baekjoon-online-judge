#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long ans = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    int max = v.back();
    for (int i = n - 2; i >= 0; i--)
      if (v[i] > max)
        max = v[i];
      else
        ans += max - v[i];
    cout << ans << '\n';
  }
  return 0;
}