// 5214: 환승
//
// - 문제
// 아주 먼 미래에 사람들이 가장 많이 사용하는 대중교통은 하이퍼튜브이다. 하이퍼튜브 하나는 역 K개를 서로 연결한다. 1번역에서 N번역으로 가는데 방문하는 최소 역의 수는 몇 개일까?
//
// - 입력
// 첫째 줄에 역의 수 N과 한 하이퍼튜브가 서로 연결하는 역의 개수 K, 하이퍼튜브의 개수 M이 주어진다. (1 ≤ N ≤ 100,000, 1 ≤ K, M ≤ 1000)
// 다음 M개 줄에는 하이퍼튜브의 정보가 한 줄에 하나씩 주어진다. 총 K개 숫자가 주어지며, 이 숫자는 그 하이퍼튜브가 서로 연결하는 역의 번호이다.
//
// - 출력
// 첫째 줄에 1번역에서 N번역으로 가는데 방문하는 역의 개수의 최솟값을 출력한다. 만약, 갈 수 없다면 -1을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int N, K, M;
vector<int> graph[101001];
int visited[101001] = {0};

void bfs(int s) {
  queue<int> q;
  q.push(s);
  visited[s] = 1;
  while (!q.empty()) {
    int x = q.front();
    if (x == N)
      return;
    q.pop();
    for (int nx : graph[x]) {
      if (nx > N) {
        visited[nx] = visited[x];
        q.push(nx);
      } else if (!visited[nx]) {
        visited[nx] = visited[x] + 1;
        q.push(nx);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K >> M;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < K; j++) {
      int x;
      cin >> x;
      graph[x].push_back(N + i + 1);
      graph[N + i + 1].push_back(x);
    }
  }
  bfs(1);
  cout << (visited[N] ? visited[N] : -1) << '\n';
  return 0;
}