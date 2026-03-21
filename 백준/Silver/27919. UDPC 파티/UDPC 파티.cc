#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string V, ans = "";
  cin >> V;
  int uc = 0, dp = 0;
  for (char i : V)
    if (i == 'U' || i == 'C')
      uc++;
    else
      dp++;
  if (2 * uc > dp + 1)
    ans += 'U';
  if (dp > 0)
    ans += "DP";
  cout << ans;
  return 0;
}