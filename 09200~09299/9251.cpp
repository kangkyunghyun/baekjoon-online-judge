// 9251: LCS
//
// - 문제
// LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
// 예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.
//
// - 입력
// 첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.
//
// - 출력
// 첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  vector<vector<int>> graph(a.size() + 1, vector<int>(b.size() + 1, 0));
  for (int i = 1; i <= a.size(); i++)
    for (int j = 1; j <= b.size(); j++)
      if (a[i - 1] == b[j - 1])
        graph[i][j] = graph[i - 1][j - 1] + 1;
      else
        graph[i][j] = max(graph[i - 1][j], graph[i][j - 1]);
  cout << graph[a.size()][b.size()];
  return 0;
}