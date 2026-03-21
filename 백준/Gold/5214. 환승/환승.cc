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