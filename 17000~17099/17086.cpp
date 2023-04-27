// 17086: 아기 상어 2
//
// - 문제
// N×M 크기의 공간에 아기 상어 여러 마리가 있다. 공간은 1×1 크기의 정사각형 칸으로 나누어져 있다. 한 칸에는 아기 상어가 최대 1마리 존재한다.
// 어떤 칸의 안전 거리는 그 칸과 가장 거리가 가까운 아기 상어와의 거리이다. 두 칸의 거리는 하나의 칸에서 다른 칸으로 가기 위해서 지나야 하는 칸의 수이고, 이동은 인접한 8방향(대각선 포함)이 가능하다.
// 안전 거리가 가장 큰 칸을 구해보자.
//
// - 입력
// 첫째 줄에 공간의 크기 N과 M(2 ≤ N, M ≤ 50)이 주어진다. 둘째 줄부터 N개의 줄에 공간의 상태가 주어지며, 0은 빈 칸, 1은 아기 상어가 있는 칸이다. 빈 칸과 상어의 수가 각각 한 개 이상인 입력만 주어진다.
//
// - 출력
// 첫째 줄에 안전 거리의 최댓값을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int n, m, a[50][50], ans = 0;
int dx[] = {-1, 1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};

void bfs(int xx, int yy) {
  int cnt = 0;
  queue<pair<pair<int, int>, int>> q;
  vector<vector<int>> visited(50, vector<int>(50, -1));
  q.push({{xx, yy}, cnt});
  visited[xx][yy] = cnt;
  while (!q.empty()) {
    auto [x, y] = q.front().first;
    cnt = q.front().second + 1;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        continue;
      if (visited[nx][ny] == -1) {
        visited[nx][ny] = cnt;
        q.push({{nx, ny}, cnt});
        if (a[nx][ny]) {
          ans = max(ans, cnt);
          return;
        }
      }
    }
  }
  ans = cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<int, int>> v;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (!a[i][j])
        v.push_back({i, j});
    }
  for (int i = 0; i < v.size(); i++)
    bfs(v[i].first, v[i].second);
  cout << ans;
  return 0;
}