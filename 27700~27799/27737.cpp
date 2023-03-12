// 27737: 버섯 농장
//
// - 문제
// 농부 해강이는 N × N 칸으로 이루어진 나무판에서 버섯 농사를 짓는다. 나무판은 버섯이 자랄 수 있는 칸과 없는 칸으로 이루어져 있다.
// 해강이는 M개의 버섯 포자를 가지고 있다. 버섯 포자는 버섯이 자랄 수 있는 칸에만 심을 수 있다.
// 각 버섯 포자는 포자가 심어진 칸을 포함해 최대 K개의 연결된 (버섯이 자랄 수 있는) 칸에 버섯을 자라게 한다. 이때 연결된 칸은 상하좌우로 적어도 한 변을 공유하는 칸들의 집합이라고 정의한다.
// 또한 한 칸에 버섯 포자를 여러 개 겹쳐서 심을 수 있으며, 만약 x개의 버섯 포자를 겹쳐 심으면 포자가 심어진 칸을 포함해 최대 x × K개의 연결된 (버섯이 자랄 수 있는) 칸에 버섯이 자란다.
// 해강이는 버섯 포자를 심을 때 최소 개수로만 심으려고 한다. 해강이가 농사가 가능할지 판단하고, 농사가 가능하다면 남은 버섯 포자의 개수를 출력하시오.
// 버섯 포자를 하나라도 사용하고 버섯이 자랄 수 있는 모든 칸에 버섯이 전부 자랐을 때 농사가 가능하다고 정의한다.
//
// - 입력
// 첫 번째 줄에 N, M, K가 공백으로 구분되어 주어진다.
// 두 번째 줄부터 N개의 줄에 나무판의 각 칸의 상태가 공백으로 구분되어 주어진다.
// 버섯이 자랄 수 있는 칸은 0, 버섯이 자랄 수 없는 칸은 1로 주어진다.
//
// - 출력
// 만약 버섯 농사가 불가능하면 IMPOSSIBLE을 출력한다.
// 버섯 농사가 가능하다면, POSSIBLE을 출력하고 다음 줄에 남은 버섯 포자의 개수를 출력한다.
//
// - 제한
// 1 ≤ N ≤ 100 
// 0 ≤ M ≤ 1,000,000
// 1 ≤ K ≤ 10^8 
// N, M, K는 모두 정수이다.

#include <bits/stdc++.h>
using namespace std;

int n, m, k, cnt, ans = 0;
int graph[101][101], visited[101][101] = {0};
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
      continue;
    if (!visited[nx][ny] && graph[nx][ny] == 0) {
      if (cnt == k) {
        ans++;
        visited[nx][ny] = 1;
        cnt = 1;
        dfs(nx, ny);
      } else {
        visited[nx][ny] = ++cnt;
        dfs(nx, ny);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> graph[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!visited[i][j] && graph[i][j] == 0) {
        cnt = 1;
        ans++;
        visited[i][j] = 1;
        dfs(i, j);
      }
  if (ans > m) {
    cout << "IMPOSSIBLE";
  } else if (ans == 0) {
    cout << "IMPOSSIBLE";
  } else {
    cout << "POSSIBLE\n"
         << m - ans;
  }
  return 0;
}