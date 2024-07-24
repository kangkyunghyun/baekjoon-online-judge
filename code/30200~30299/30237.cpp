#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0;
    cin >> n;
    vector<vector<int>> v(n), val(51);
    int cnt[51] = {0};
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int x;
        cin >> x;
        v[i].push_back(x);
        val[x].push_back(i);
        cnt[x]++;
        if (cnt[x] == 1)
          ans++;
      }
    }
    vector<int> cn(51, 0);
    int an = 0;
    for (int i = 1; i <= 50; i++) {
      if (val[i].size() == 0)
        continue;
      fill(cn.begin(), cn.end(), 0);
      int tmp = ans;
      for (int j : val[i]) {
        for (int k : v[j]) {
          cn[k]++;
        }
      }
      for (int j = 1; j <= 50; j++) {
        if (cnt[j] - cn[j] == 0 && cnt[j] > 0)
          tmp--;
      }
      if (tmp != ans)
        an = max(an, tmp);
    }
    cout << an << '\n';
  }
  return 0;
}