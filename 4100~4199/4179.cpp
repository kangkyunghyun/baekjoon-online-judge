// 4179: 불!
//
// - 문제
// 지훈이는 미로에서 일을 한다. 지훈이를 미로에서 탈출하도록 도와주자!
// 미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서 지훈이가 불에 타기전에 탈출할 수 있는지의 여부, 그리고 얼마나 빨리 탈출할 수 있는지를 결정해야한다.
// 지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다) 이동한다.
// 불은 각 지점에서 네 방향으로 확산된다.
// 지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
// 지훈이와 불은 벽이 있는 공간은 통과하지 못한다.
//
// - 입력
// 입력의 첫째 줄에는 공백으로 구분된 두 정수 R과 C가 주어진다. 단, 1 ≤ R, C ≤ 1000 이다. R은 미로 행의 개수, C는 열의 개수이다.
// 다음 입력으로 R줄동안 각각의 미로 행이 주어진다.
// 각각의 문자들은 다음을 뜻한다.
// #: 벽
// .: 지나갈 수 있는 공간
// J: 지훈이의 미로에서의 초기위치 (지나갈 수 있는 공간)
// F: 불이 난 공간
// J는 입력에서 하나만 주어진다.
//
// - 출력
// 지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는 경우 IMPOSSIBLE 을 출력한다.
// 지훈이가 미로를 탈출할 수 있는 경우에는 가장 빠른 탈출시간을 출력한다.

#include <bits/stdc++.h>
using namespace std;

string graph[1001];
int R, C;
int visitedJ[1001][1001];
int visitedF[1001][1001];
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
queue<pair<int, int>> qJ, qF;
vector<int> ans;

void bfsJ() {
  while (!qJ.empty()) {
    int x = qJ.front().first;
    int y = qJ.front().second;
    qJ.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= R || ny < 0 || ny >= C)
        continue;
      if (!visitedJ[nx][ny] && graph[nx][ny] != '#') {
        visitedJ[nx][ny] = visitedJ[x][y] + 1;
        qJ.push({nx, ny});
      }
    }
  }
}

void bfsF() {
  while (!qF.empty()) {
    int x = qF.front().first;
    int y = qF.front().second;
    qF.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= R || ny < 0 || ny >= C)
        continue;
      if (!visitedF[nx][ny] && graph[nx][ny] != '#') {
        visitedF[nx][ny] = visitedF[x][y] + 1;
        qF.push({nx, ny});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    cin >> graph[i];
    for (int j = 0; j < C; j++) {
      visitedJ[i][j] = 0;
      visitedF[i][j] = 0;
      if (graph[i][j] == 'J') {
        qJ.push({i, j});
        visitedJ[i][j] = 1;
      }
      if (graph[i][j] == 'F') {
        qF.push({i, j});
        visitedF[i][j] = 1;
      }
    }
  }
  bfsJ();
  bfsF();
  for (int i = 0; i < R; i++) {
    if (visitedJ[i][0] && (visitedJ[i][0] < visitedF[i][0] || !visitedF[i][0]))
      ans.push_back(visitedJ[i][0]);
    if (visitedJ[i][C - 1] && (visitedJ[i][C - 1] < visitedF[i][C - 1] || !visitedF[i][C - 1]))
      ans.push_back(visitedJ[i][C - 1]);
  }
  for (int i = 0; i < C; i++) {
    if (visitedJ[0][i] && (visitedJ[0][i] < visitedF[0][i] || !visitedF[0][i]))
      ans.push_back(visitedJ[0][i]);
    if (visitedJ[R - 1][i] && (visitedJ[R - 1][i] < visitedF[R - 1][i] || !visitedF[R - 1][i]))
      ans.push_back(visitedJ[R - 1][i]);
  }
  if (ans.empty())
    cout << "IMPOSSIBLE\n";
  else
    cout << *min_element(ans.begin(), ans.end()) << '\n';
  return 0;
}