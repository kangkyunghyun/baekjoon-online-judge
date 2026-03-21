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

void check() {
  for (int i = 0; i < R; i++) {
    if ((visitedJ[i][0] && visitedJ[i][0] < visitedF[i][0]) || (visitedJ[i][0] && !visitedF[i][0]))
      ans.push_back(visitedJ[i][0]);
    if ((visitedJ[i][C - 1] && visitedJ[i][C - 1] < visitedF[i][C - 1]) || (visitedJ[i][C - 1] && !visitedF[i][C - 1]))
      ans.push_back(visitedJ[i][C - 1]);
  }
  for (int i = 0; i < C; i++) {
    if ((visitedJ[0][i] && visitedJ[0][i] < visitedF[0][i]) || (visitedJ[0][i] && !visitedF[0][i]))
      ans.push_back(visitedJ[0][i]);
    if ((visitedJ[R - 1][i] && visitedJ[R - 1][i] < visitedF[R - 1][i]) || (visitedJ[R - 1][i] && !visitedF[R - 1][i]))
      ans.push_back(visitedJ[R - 1][i]);
  }
  sort(ans.begin(), ans.end());
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
  check();
  if (ans.empty())
    cout << "IMPOSSIBLE\n";
  else
    cout << ans[0] << '\n';
  return 0;
}