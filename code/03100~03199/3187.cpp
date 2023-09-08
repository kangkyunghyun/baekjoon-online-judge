// 3187: 양치기 꿍
//
// - 문제
// 양치기 꿍은 맨날 늑대가 나타났다고 마을 사람들을 속였지만 이젠 더이상 마을 사람들이 속지 않는다. 화가 난 꿍은 복수심에 불타 아예 늑대들을 양들이 있는 울타리안에 마구 집어넣어 양들을 잡아먹게 했다.
// 하지만 양들은 보통 양들이 아니다. 같은 울타리 영역 안의 양들의 숫자가 늑대의 숫자보다 더 많을 경우 늑대가 전부 잡아먹힌다. 물론 그 외의 경우는 양이 전부 잡아먹히겠지만 말이다.
// 꿍은 워낙 똑똑했기 때문에 이들의 결과는 이미 알고있다. 만약 빈 공간을 '.'(점)으로 나타내고 울타리를 '#', 늑대를 'v', 양을 'k'라고 나타낸다면 여러분은 몇 마리의 양과 늑대가 살아남을지 계산할 수 있겠는가?
// 단, 울타리로 막히지 않은 영역에는 양과 늑대가 없으며 양과 늑대는 대각선으로 이동할 수 없다.
//
// - 입력
// 입력의 첫 번째 줄에는 각각 영역의 세로와 가로의 길이를 나타내는 두 개의 정수 R, C (3 ≤ R, C ≤ 250)가 주어진다.
// 다음 각 R줄에는 C개의 문자가 주어지며 이들은 위에서 설명한 기호들이다.
//
// - 출력
// 살아남게 되는 양과 늑대의 수를 각각 순서대로 출력한다.

#include <bits/stdc++.h>
using namespace std;

int r, c, v, k;
string arr[250];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int visited[250][250] = {0};

void bfs(int xx, int yy) {
  int vv = 0, kk = 0;
  queue<pair<int, int>> q;
  visited[xx][yy] = 1;
  q.push({xx, yy});
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    if (arr[x][y] == 'v')
      vv++;
    else if (arr[x][y] == 'k')
      kk++;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= r || ny >= c)
        continue;
      if (!visited[nx][ny] && arr[nx][ny] != '#') {
        visited[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }
  if (kk > vv)
    v -= vv;
  else
    k -= kk;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> r >> c;
  vector<pair<int, int>> xy;
  for (int i = 0; i < r; i++) {
    cin >> arr[i];
    for (int j = 0; j < c; j++) {
      if (arr[i][j] == 'v') {
        v++;
        xy.push_back({i, j});
      } else if (arr[i][j] == 'k') {
        k++;
        xy.push_back({i, j});
      }
    }
  }
  for (auto [x, y] : xy)
    if (!visited[x][y])
      bfs(x, y);
  cout << k << ' ' << v;
  return 0;
}