#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, ans = INT_MAX;
  string s;
  cin >> n >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    if (s[i] == 'R')
      v[i] = 0;
    else if (s[i] == 'G')
      v[i] = 1;
    else
      v[i] = 2;
  for (int i = 0; i < 3; i++) {
    vector<int> a = v;
    int cnt = 0;
    for (int j = 0; j < n - 2; j++) {
      while (a[j] != i) {
        a[j] = (a[j] + 1) % 3;
        a[j + 1] = (a[j + 1] + 1) % 3;
        a[j + 2] = (a[j + 2] + 1) % 3;
        cnt++;
      }
    }
    if (a[n - 2] == i && a[n - 1] == i)
      ans = min(ans, cnt);
  }
  cout << (ans == INT_MAX ? -1 : ans);
  return 0;
}