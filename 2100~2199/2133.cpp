// 2133: 타일 채우기
//
// - 문제
// 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.
//
// - 입력
// 첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.
//
// - 출력
// 첫째 줄에 경우의 수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> dp(n + 1, 0);
  dp[0] = 1, dp[2] = 3;
  for (int i = 4; i <= n; i += 2) {
    dp[i] = dp[2] * dp[i - 2];
    for (int j = 4; j <= i; j += 2)
      dp[i] += 2 * dp[i - j];
  }
  cout << dp[n];
  return 0;
}