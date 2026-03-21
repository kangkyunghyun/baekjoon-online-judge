#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, ans = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  vector<int> result;
  if (n % 2) {
    for (int i = 0; i < n / 2; i++) {
      result.push_back(v[n - i - 1]);
      result.push_back(v[i]);
    }
    result.push_back(v[n / 2]);
  } else {
    for (int i = 0; i < n / 2; i++) {
      result.push_back(v[n - i - 1]);
      result.push_back(v[i]);
    }
  }
  ans += result[0];
  for (int i = 1; i < n; i++)
    ans += max(0, result[i] - result[i - 1]);
  cout << ans;
  return 0;
}