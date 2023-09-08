// 2178: 미로 탐색
//
// - 문제
// N×M크기의 배열로 표현되는 미로가 있다.
// 1	0	1	1	1	1
// 1	0	1	0	1	0
// 1	0	1	0	1	1
// 1	1	1	0	1	1
// 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
// 위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
//
// - 입력
// 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.
//
// - 출력
// 첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph(101, vector<int>(101));
vector<vector<int>> visited(101, vector<int>(101, 0));
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int xx, int yy) {
  queue<pair<int, int>> q;
  q.push({xx, yy});
  visited[xx][yy] = 1;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (visited[n - 1][m - 1])
      return;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (ny >= 0 && nx >= 0 && ny < m && nx < n && graph[nx][ny] == 1 && !visited[nx][ny]) {
        q.push({nx, ny});
        visited[nx][ny] = visited[x][y] + 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++)
      graph[i][j] = s[j] - '0';
  }
  bfs(0, 0);
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (ans < visited[i][j])
        ans = visited[i][j];
  cout << ans;
  return 0;
}