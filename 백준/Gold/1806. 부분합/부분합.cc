#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, s;
  cin >> n >> s;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int left = 0, right = 0, sum = v[0], ans = n + 1;
  while (left <= right && right < n)
    if (sum < s) {
      sum += v[++right];
    } else if (sum > s) {
      ans = min(ans, right - left + 1);
      sum -= v[left++];
    } else {
      ans = min(ans, right - left + 1);
      sum += v[++right];
    }
  cout << (ans == n + 1 ? 0 : ans);
  return 0;
}