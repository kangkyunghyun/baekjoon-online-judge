#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, ans = 1;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int max = v[n - 1];
  for (int i = n - 2; i >= 0; i--)
    if (v[i] > max) {
      ans++;
      max = v[i];
    }
  cout << ans;
  return 0;
}