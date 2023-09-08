// 25500: 무자비한 최단 경로
//
// - 문제
// 신촌 초급반 학생들은 그래프에서 최단 경로를 구하는 여러 방법들을 공부했다. 그들에게 벽을 느끼게 하고 싶었던 djs100201은 무자비한 최단 경로 문제를 만들었다.
// 1번 부터 N번까지 번호가 매겨진 총 N개의 마을이 있다. i번째 마을의 위치는 (x_i,y_i,z_i)로 표현된다.
// 1이상 N이하의 서로 다른 두 정수 i,j에 대해, i번 마을과 j번 마을을 잇는 \min(|x_i-x_j|,|y_i-y_j|)만큼의 길이를 가진 양방향 도로가 존재한다.
// 또한 만약 z_i+z_j가 K로 나누어 떨어진다면, i번 마을과 j번 마을을 잇는 z_i+z_j의 길이를 가진 양방향 도로 또한 존재한다.
// 이때 1번 마을에서 각 마을로 도착하는 최단 경로의 길이를 모두 구해보자.
//
// - 입력
// 첫째 줄에 정수 N과 K가 공백으로 구분되어 주어진다. (1 ≤ N,K ≤ 200\,000)
// 둘째 줄부터 N개의 줄에 걸쳐 i+1번째 줄에는 i번 마을의 위치를 나타내는 세 정수 (x_i,y_i,z_i)가 공백으로 구분되어 주어진다. (0 ≤ x_i,y_i,z_i ≤ 10^9) 
//
// - 출력
// 총 N줄에 걸쳐 답을 출력한다. i번째 줄에는 i번 마을에 도착하는 최단 경로의 길이를 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define ll long long
#define p pair<ll, int>

struct town {
  int i, x, y, z;
};

int N, K;
vector<town> xyz;
ll dist[400001];
vector<p> edge[400001];

void dijkstra() {
  fill(dist, dist + N + K, INF);
  priority_queue<p> pq;
  dist[0] = 0;
  pq.push({0, 0});
  while (!pq.empty()) {
    int cost = -pq.top().first;
    int curr = pq.top().second;
    pq.pop();
    if (dist[curr] < cost)
      continue;
    for (p node : edge[curr]) {
      int next = node.first, d = cost + node.second;
      if (dist[next] > d) {
        dist[next] = d;
        pq.push({-d, next});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    xyz.push_back({i, x, y, z});
  }
  sort(xyz.begin(), xyz.end(), [](auto a, auto b) { return a.x < b.x; });
  for (int i = 0; i < N - 1; i++) {
    edge[xyz[i].i].push_back({xyz[i + 1].i, xyz[i + 1].x - xyz[i].x});
    edge[xyz[i + 1].i].push_back({xyz[i].i, xyz[i + 1].x - xyz[i].x});
  }
  sort(xyz.begin(), xyz.end(), [](auto a, auto b) { return a.y < b.y; });
  for (int i = 0; i < N - 1; i++) {
    edge[xyz[i].i].push_back({xyz[i + 1].i, xyz[i + 1].y - xyz[i].y});
    edge[xyz[i + 1].i].push_back({xyz[i].i, xyz[i + 1].y - xyz[i].y});
  }
  for (int i = 0; i < N; i++) {
    edge[xyz[i].i].push_back({N + (xyz[i].z % K), xyz[i].z});
    edge[N + (K - xyz[i].z % K) % K].push_back({xyz[i].i, xyz[i].z});
  }
  dijkstra();
  for (int i = 0; i < N; i++)
    cout << dist[i] << '\n';
  return 0;
}