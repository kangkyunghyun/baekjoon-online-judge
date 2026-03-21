#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;
  cin >> a >> b;
  int a_size = a.size();
  int b_size = b.size();
  vector<vector<int>> dp(a_size + 1, vector<int>(b_size + 1, 0));
  for (int i = 1; i <= a_size; i++)
    for (int j = 1; j <= b_size; j++)
      if (a[i - 1] == b[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
  int len = dp[a_size][b_size];
  cout << len << '\n';
  vector<char> LCS(len, ' ');
  int x = a_size, y = b_size;
  while (len > 0) {
    if (dp[x - 1][y] == len) {
      x--;
    } else if (dp[x][y - 1] == len) {
      y--;
    } else {
      LCS[len - 1] = a[x - 1];
      x--;
      y--;
      len--;
    }
  }
  for (char i : LCS)
    cout << i;
  return 0;
}