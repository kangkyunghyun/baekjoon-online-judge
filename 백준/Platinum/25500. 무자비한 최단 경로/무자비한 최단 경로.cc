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