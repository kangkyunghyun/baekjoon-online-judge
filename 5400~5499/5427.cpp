// 5427: 불
//
// - 문제
// 상근이는 빈 공간과 벽으로 이루어진 건물에 갇혀있다. 건물의 일부에는 불이 났고, 상근이는 출구를 향해 뛰고 있다.
// 매 초마다, 불은 동서남북 방향으로 인접한 빈 공간으로 퍼져나간다. 벽에는 불이 붙지 않는다. 상근이는 동서남북 인접한 칸으로 이동할 수 있으며, 1초가 걸린다. 상근이는 벽을 통과할 수 없고, 불이 옮겨진 칸 또는 이제 불이 붙으려는 칸으로 이동할 수 없다. 상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.
// 빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 수 있는지 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개이다.
// 각 테스트 케이스의 첫째 줄에는 빌딩 지도의 너비와 높이 w와 h가 주어진다. (1 ≤ w,h ≤ 1000)
// 다음 h개 줄에는 w개의 문자, 빌딩의 지도가 주어진다.
// '.': 빈 공간
// '#': 벽
// '@': 상근이의 시작 위치
// '*': 불
// 각 지도에 @의 개수는 하나이다.
//
// - 출력
// 각 테스트 케이스마다 빌딩을 탈출하는데 가장 빠른 시간을 출력한다. 빌딩을 탈출할 수 없는 경우에는 "IMPOSSIBLE"을 출력한다.

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