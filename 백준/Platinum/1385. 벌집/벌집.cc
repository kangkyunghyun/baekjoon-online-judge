#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int a, b, x = 600, y = 600, cnt = 1, wrap = 1, start_x, start_y, end_x, end_y, graph[1201][1201], dx[] = {0, 0, 1, 1, -1, -1}, dy[] = {1, -1, 0, 1, 0, -1};
pii path[1201][1201];

void bfs(int x, int y) {
  queue<pii> q;
  q.push({x, y});
  path[x][y] = {-1, -1};
  while (!q.empty()) {
    pii curr = q.front();
    q.pop();
    for (int i = 0; i < 6; i++) {
      int nx = curr.first + dx[i], ny = curr.second + dy[i];
      if (nx < 0 || ny < 0 || nx > 1200 || ny > 1200)
        continue;
      if (graph[nx][ny] == 0 || path[nx][ny].first != 0 && path[nx][ny].second != 0)
        continue;
      q.push({nx, ny});
      path[nx][ny] = {curr.first, curr.second};
      if (graph[nx][ny] == b)
        return;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  if (a == b) {
    cout << a;
    return 0;
  }
  graph[x][y] = cnt++;
  while (1) {
    y++;
    graph[x][y] = cnt++;
    if (cnt - 1 == a) {
      start_x = x;
      start_y = y;
    }
    if (cnt - 1 == b) {
      end_x = x;
      end_y = y;
    }
    for (int i = 0; i < wrap - 1; i++) {
      x++;
      y++;
      graph[x][y] = cnt++;
      if (cnt - 1 == a) {
        start_x = x;
        start_y = y;
      }
      if (cnt - 1 == b) {
        end_x = x;
        end_y = y;
      }
    }
    for (int i = 0; i < wrap; i++) {
      x++;
      graph[x][y] = cnt++;
      if (cnt - 1 == a) {
        start_x = x;
        start_y = y;
      }
      if (cnt - 1 == b) {
        end_x = x;
        end_y = y;
      }
    }
    for (int i = 0; i < wrap; i++) {
      y--;
      graph[x][y] = cnt++;
      if (cnt - 1 == a) {
        start_x = x;
        start_y = y;
      }
      if (cnt - 1 == b) {
        end_x = x;
        end_y = y;
      }
    }
    for (int i = 0; i < wrap; i++) {
      x--;
      y--;
      graph[x][y] = cnt++;
      if (cnt - 1 == a) {
        start_x = x;
        start_y = y;
      }
      if (cnt - 1 == b) {
        end_x = x;
        end_y = y;
      }
    }
    for (int i = 0; i < wrap; i++) {
      x--;
      graph[x][y] = cnt++;
      if (cnt - 1 == a) {
        start_x = x;
        start_y = y;
      }
      if (cnt - 1 == b) {
        end_x = x;
        end_y = y;
      }
    }
    for (int i = 0; i < wrap; i++) {
      y++;
      graph[x][y] = cnt++;
      if (cnt - 1 == a) {
        start_x = x;
        start_y = y;
      }
      if (cnt - 1 == b) {
        end_x = x;
        end_y = y;
      }
    }
    wrap++;
    if (cnt > 1000000)
      break;
  }
  bfs(start_x, start_y);
  vector<int> ans;
  ans.push_back(b);
  while (1) {
    pii curr = path[end_x][end_y];
    ans.push_back(graph[curr.first][curr.second]);
    if (graph[curr.first][curr.second] == a)
      break;
    end_x = curr.first;
    end_y = curr.second;
  }
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] << ' ';
  return 0;
}