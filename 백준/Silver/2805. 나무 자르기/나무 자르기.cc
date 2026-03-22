#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, ans = 0;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  long long low = 0, high = v.back(), mid;
  while (low <= high) {
    mid = (low + high) / 2;
    long long cnt = 0;
    for (int i = 0; i < n; i++)
      if (v[i] - mid > 0)
        cnt += v[i] - mid;
    if (cnt >= m) {
      low = mid + 1;
      if (mid > ans)
        ans = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}