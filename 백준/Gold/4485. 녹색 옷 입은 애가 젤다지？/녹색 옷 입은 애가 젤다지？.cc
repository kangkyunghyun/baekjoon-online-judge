#include <bits/stdc++.h>
using namespace std;

#define INF 2147483647

int N;
vector<vector<int>> graph(126, vector<int>(126, 0)), dist(126, vector<int>(126, INF)), visited(126, vector<int>(126, 0));
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void init() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      visited[i][j] = 0;
      dist[i][j] = INF;
    }
}

int dijkstra(int xx, int yy) {
  init();
  dist[xx][yy] = graph[xx][yy];
  pq.push({0, {xx, yy}});
  while (!pq.empty()) {
    int x, y;
    do {
      x = pq.top().second.first;
      y = pq.top().second.second;
      pq.pop();
    } while (!pq.empty() && visited[x][y]);

    if (visited[x][y])
      break;
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < N && ny >= 0 && ny < N && dist[nx][ny] > dist[x][y] + graph[nx][ny]) {
        dist[nx][ny] = dist[x][y] + graph[nx][ny];
        pq.push({dist[nx][ny], {nx, ny}});
      }
    }
  }
  return dist[N - 1][N - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int cnt = 1;
  while (1) {
    cin >> N;
    if (!N)
      break;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        cin >> graph[i][j];
    cout << "Problem " << cnt << ": " << dijkstra(0, 0) << '\n';
    cnt++;
  }
  return 0;
}