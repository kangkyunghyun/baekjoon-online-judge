#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m, cnt = 0;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  int start = 0, end = 0;
  while (end < n) {
    int sum = v[start] + v[end];
    if (sum == m)
      cnt++;
    if (end == n - 1) {
      start++;
      end = start + 1;
    } else {
      end++;
    }
  }
  cout << cnt;
  return 0;
}