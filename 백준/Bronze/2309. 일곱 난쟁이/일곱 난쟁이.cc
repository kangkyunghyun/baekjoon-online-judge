#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<int> v(9);
  for (int i = 0; i < 9; i++)
    cin >> v[i];
  int sum = accumulate(v.begin(), v.end(), 0);
  for (int i = 0; i < 8; i++)
    for (int j = i + 1; j < 9; j++)
      if (sum - v[i] - v[j] == 100) {
        vector<int> ans;
        for (int k = 0; k < 9; k++) {
          if (k == i || k == j)
            continue;
          ans.push_back(v[k]);
        }
        sort(ans.begin(), ans.end());
        for (int e : ans)
          cout << e << '\n';
        return 0;
      }
  return 0;
}