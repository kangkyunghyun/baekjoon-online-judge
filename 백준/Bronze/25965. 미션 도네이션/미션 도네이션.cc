#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    long long m, k, d, a, ans = 0;
    cin >> m;
    vector<vector<int>> v;
    while (m--) {
      vector<int> temp(3);
      cin >> temp[0] >> temp[1] >> temp[2];
      v.push_back(temp);
    }
    cin >> k >> d >> a;
    for (auto vt : v) {
      long long sum = k * vt[0] - d * vt[1] + a * vt[2];
      if (sum >= 0)
        ans += sum;
    }
    cout << ans << '\n';
  }
  return 0;
}