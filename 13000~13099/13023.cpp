// 13023: ABCDE
//
// - 문제
// BOJ 알고리즘 캠프에는 총 N명이 참가하고 있다. 사람들은 0번부터 N-1번으로 번호가 매겨져 있고, 일부 사람들은 친구이다.
// 오늘은 다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지 구해보려고 한다.
// A는 B와 친구다.
// B는 C와 친구다.
// C는 D와 친구다.
// D는 E와 친구다.
// 위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)이 주어진다.
// 둘째 줄부터 M개의 줄에는 정수 a와 b가 주어지며, a와 b가 친구라는 뜻이다. (0 ≤ a, b ≤ N-1, a ≠ b) 같은 친구 관계가 두 번 이상 주어지는 경우는 없다.
//
// - 출력
// 문제의 조건에 맞는 A, B, C, D, E가 존재하면 1을 없으면 0을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<vector<int>> graph(2000, vector<int>(0));
vector<int> visited(2000, 0);

void dfs(int x, int cnt) {
  if (cnt == 4) {
    ans = 1;
    return;
  }
  visited[x] = 1;
  for (int i = 0; i < graph[x].size(); i++) {
    int next = graph[x][i];
    if (!visited[next])
      dfs(next, cnt + 1);
  }
  visited[x] = 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  for (int i = 0; i < n; i++) {
    if (ans)
      break;
    dfs(i, 0);
  }
  cout << ans;
  return 0;
}