#include <bits/stdc++.h>
using namespace std;

string graph[1001];
int w, h;
int visitedJ[1001][1001];
int visitedF[1001][1001];
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
queue<pair<int, int>> qS, qF;
vector<int> ans;

void bfsS() {
  while (!qS.empty()) {
    int x = qS.front().first;
    int y = qS.front().second;
    qS.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w)
        continue;
      if (!visitedJ[nx][ny] && graph[nx][ny] != '#') {
        visitedJ[nx][ny] = visitedJ[x][y] + 1;
        qS.push({nx, ny});
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
      if (nx < 0 || nx >= h || ny < 0 || ny >= w)
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
  int t;
  cin >> t;
  while (t--) {
    ans.clear();
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
      cin >> graph[i];
      for (int j = 0; j < w; j++) {
        visitedJ[i][j] = 0;
        visitedF[i][j] = 0;
        if (graph[i][j] == '@') {
          qS.push({i, j});
          visitedJ[i][j] = 1;
        }
        if (graph[i][j] == '*') {
          qF.push({i, j});
          visitedF[i][j] = 1;
        }
      }
    }
    bfsS();
    bfsF();
    for (int i = 0; i < h; i++) {
      if (visitedJ[i][0] && (visitedJ[i][0] < visitedF[i][0] || !visitedF[i][0]))
        ans.push_back(visitedJ[i][0]);
      if (visitedJ[i][w - 1] && (visitedJ[i][w - 1] < visitedF[i][w - 1] || !visitedF[i][w - 1]))
        ans.push_back(visitedJ[i][w - 1]);
    }
    for (int i = 0; i < w; i++) {
      if (visitedJ[0][i] && (visitedJ[0][i] < visitedF[0][i] || !visitedF[0][i]))
        ans.push_back(visitedJ[0][i]);
      if (visitedJ[h - 1][i] && (visitedJ[h - 1][i] < visitedF[h - 1][i] || !visitedF[h - 1][i]))
        ans.push_back(visitedJ[h - 1][i]);
    }
    if (ans.empty())
      cout << "IMPOSSIBLE\n";
    else
      cout << *min_element(ans.begin(), ans.end()) << '\n';
  }
  return 0;
}