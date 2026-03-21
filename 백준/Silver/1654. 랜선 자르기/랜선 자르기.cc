#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int k, n, ans = 0;
  cin >> k >> n;
  vector<int> v(k);
  for (int i = 0; i < k; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  long long low = 1, high = v.back();
  while (low <= high) {
    long long mid = (low + high) / 2, cnt = 0;
    for (int i = 0; i < k; i++)
      cnt += v[i] / mid;
    if (cnt >= n) {
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