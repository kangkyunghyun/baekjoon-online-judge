// 9663: N-Queen
//
// - 문제
// N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
// N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 N이 주어진다. (1 ≤ N < 15)
//
// - 출력
// 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> graph(15, 0);

int check(int row) {
  for (int i = 0; i < row; i++)
    if (graph[i] == graph[row] || abs(row - i) == abs(graph[row] - graph[i]))
      return 0;
  return 1;
}

void dfs(int row) {
  if (row == n) {
    ans++;
    return;
  }
  for (int col = 0; col < n; col++) {
    graph[row] = col;
    if (check(row))
      dfs(row + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  dfs(0);
  cout << ans;
  return 0;
}