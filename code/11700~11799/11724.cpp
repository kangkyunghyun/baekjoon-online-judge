// 11724: 연결 요소의 개수
//
// - 문제
// 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.
//
// - 출력
// 첫째 줄에 연결 요소의 개수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<vector<int>> graph(1001, vector<int>(1001));
vector<int> visited(1001, 0);

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visited[start] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 1; i <= n; i++)
      if (graph[x][i] && !visited[i]) {
        q.push(i);
        visited[i] = 1;
      }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    graph[x][y] = 1;
    graph[y][x] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (!visited[i]) {
      bfs(i);
      ans++;
    }
  cout << ans;
  return 0;
}