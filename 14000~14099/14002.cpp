// 14002: 가장 긴 증가하는 부분 수열 4
//
// - 문제
// 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
// 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
//
// - 입력
// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
// 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
//
// - 출력
// 첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
// 둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다. 그러한 수열이 여러가지인 경우 아무거나 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> v(n), dp(n, 1), prev(n, -1);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
      if (v[i] > v[j]) {
        if (dp[i] < dp[j] + 1)
          prev[i] = j;
        dp[i] = max(dp[i], dp[j] + 1);
      }
  int idx = 0, m = 0;
  for (int i = 0; i < n; i++)
    if (dp[i] > m) {
      m = dp[i];
      idx = i;
    }
  cout << m << '\n';
  int tmp = idx;
  vector<int> ans;
  while (tmp >= 0) {
    ans.push_back(v[tmp]);
    tmp = prev[tmp];
  }
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}