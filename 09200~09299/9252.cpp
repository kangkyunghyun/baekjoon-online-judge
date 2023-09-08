// 9252: LCS 2
//
// - 문제
// LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
// 예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.
//
// - 입력
// 첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.
//
// - 출력
// 첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.
// LCS가 여러 가지인 경우에는 아무거나 출력하고, LCS의 길이가 0인 경우에는 둘째 줄을 출력하지 않는다.

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