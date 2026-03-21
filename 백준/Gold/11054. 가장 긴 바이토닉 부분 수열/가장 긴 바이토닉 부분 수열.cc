#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m = 0, ans = 0;
  cin >> n;
  vector<int> v(n), asc(n, 1), dsc(n, 1);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (v[i] > v[j]) {
        asc[i] = max(asc[i], asc[j] + 1);
      }
    }
    if (asc[i] > m) {
      m = asc[i];
      for (int a = i; a < n; a++) {
        for (int b = i; b < a; b++) {
          if (v[a] < v[b]) {
            dsc[a] = max(dsc[a], dsc[b] + 1);
          }
        }
      }
      ans = max(ans, m + *max_element(dsc.begin(), dsc.end()) - 1);
    }
    fill(dsc.begin(), dsc.end(), 1);
  }
  cout << ans << '\n';
  return 0;
}