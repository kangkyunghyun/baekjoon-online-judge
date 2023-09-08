// 2206: 벽 부수고 이동하기
//
// - 문제
// N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.
// 만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.
// 한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.
// 맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.
//
// - 출력
// 첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int n, m;
string graph[1001];
int visited[1001][1001][2];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int bfs(int cc, int xx, int yy) {
  queue<pair<int, pair<int, int>>> q;
  q.push({cc, {xx, yy}});
  visited[xx][yy][cc] = 1;
  while (!q.empty()) {
    int c = q.front().first;
    int x = q.front().second.first;
    int y = q.front().second.second;
    q.pop();
    if (x == n - 1 && y == m - 1)
      return visited[n - 1][m - 1][c];
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (graph[nx][ny] == '1' && c == 1) {
        visited[nx][ny][c - 1] = visited[x][y][c] + 1;
        q.push({c - 1, {nx, ny}});
      } else if (graph[nx][ny] == '0' && visited[nx][ny][c] == 0) {
        visited[nx][ny][c] = visited[x][y][c] + 1;
        q.push({c, {nx, ny}});
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> graph[i];
  cout << bfs(1, 0, 0) << '\n';
  return 0;
}