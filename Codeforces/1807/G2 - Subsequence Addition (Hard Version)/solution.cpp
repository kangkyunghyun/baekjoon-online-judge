#include <bits/stdc++.h>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, flag = 0;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    sort(v.begin(), v.end());
    if (v[0] != 1) {
      cout << "NO
";
      continue;
    }
    string ans = "YES
";
    long long s = 1;
    for (int i = 1; i < n; i++) {
      if (v[i] > s) {
        ans = "NO
";
        break;
      }
      s += v[i];
    }
    cout << ans;
  }
  return 0;
}