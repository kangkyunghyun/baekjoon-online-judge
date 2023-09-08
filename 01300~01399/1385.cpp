// 1385: 벌집
//
// - 문제
// 지민이는 벌집에 빠졌다. 출구가 어디에 있는지는 아는데, 어떻게 가야 하는지를 모른다.
// 그곳에 있는 벌들에 의하면 방의 번호는 다음과 같이 붙는다.
// 지민이는 지금 a번 방에 있다. b번 방이 출구인데 어떻게 이동해야 할까? 집에는 민식이가 기다리고 있기 때문에, 가장 빠르게 탈출하기 위해 최단거리로 움직이고 싶다.
//
// - 입력
// 첫째 줄에는 당신이 있는 방의 번호 a와 출구가 있는 방의 번호 b가 주어진다.1 ≤ a, b ≤ 1,000,000)
//
// - 출력
// 첫째 줄에 탈출을 위해 최단거리로 지나는 방의 번호를 공백으로 구분해 출력한다.

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