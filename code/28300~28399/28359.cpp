#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m = 0;
  cin >> n;
  vector<int> a(n), cnt(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(a.begin(), a.end());
  for (int i = 1; i <= n; i++)
    m = max(m, i * cnt[i]);
  cout << accumulate(a.begin(), a.end(), m) << '\n';
  for (int i : a)
    cout << i << ' ';
  return 0;
}