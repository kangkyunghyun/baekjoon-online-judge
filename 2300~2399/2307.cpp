// 2307: 도로검문
//
// - 문제
// 그림 1은 어떤 도시의 주요 지점과 그 지점들 간의 이동시간을 나타낸 그래프이다. 그래프의 노드는 주요 지점을 나타내고 두 지점을 연결한 도로(에지)에 표시된 수는 그 도로로 이동할 때 걸리는 분 단위의 시간을 나타낸다. 두 지점 a와 b를 연결하는 도로는 도로(a,b)로 표시한다.
// 예를 들어 도로(1,2)와 도로(2,3)를 통하여 지점1에서 지점3으로 갈 때 걸리는 시간은 3분이다. 도로는 모두 양방향이라고 가정하므로 도로(a,b)와 도로(b,a)를 지날 때 걸리는 시간은 항상 같다고 한다.
// 어떤 범죄용의자가 입력 데이터에 표시된 도시로 진입하여 이 도시를 가장 빠른 시간 내에 빠져나가고자 한다. 그런데 이 사실을 알고 있는 경찰이 어떤 하나의 도로(에지)를 선택하여 이 도로에서 검문을 하려고 한다. 따라서 용의자는 이 도로를 피해서 가장 빠르게 도시를 탈출하고자 한다. 이 경우 경찰이 검문을 위하여 선택하는 도로에 따라서 용의자의 가장 빠른 탈출시간은 검문이 없을 때에 비하여 더 늘어날 수 있다.
// 문제는 도로검문을 통하여 얻을 수 있는 탈출의 최대 지연시간을 계산하는 것이다. 추가설명은 다음과 같다.
// 1. 두 개의 지점을 직접 연결하는 도로가 있는 경우, 그 도로는 유일하다.
// 2. 도시의 지점(노드)은 1에서 N번까지 N개의 연속된 정수로 표시된다.
// 3. 용의자가 도시에 진입하는 지점은 항상 1번이고 도시를 빠져 나가기 위하여 최종적으로 도달해야하는 지점은 항상 N번 지점이다.
// 4. 용의자는 검문을 피해서 가장 빨리 도시를 빠져나가고자 하고, 경찰은 적절한 도로를 선택하여 이 용이자들의 탈출시간을 최대한 지연시키고자 한다.
// 5. 각 도시 지점 간을 이동하는 시간은 항상 양의 정수이다.
// 입력 도시의 도로망에 따라서 경찰이 어떤 도로를 막으면 용의자는 도시를 탈출하지 못할 수도 있다. 이 경우 검문으로 인하여 지연시킬 수 있는 탈출시간은 무한대이다. 이 경우에는 -1을 출력해야 한다.
// 그림 1에서 볼 때 검문이 없을 경우 용의자가 도시를 탈출하는데 걸리는 시간은 4분이다. 만일 경찰이 도로(4,3)을 막으면 그 탈출시간을 지연시킬 수 없으므로 지연시간은 0이다. 만일 도로(2,3)을 막으면, 용의자들이 가장 빠르게 탈출할 수 있는 시간은 5분이므로 탈출지연시간은 1분이고, 도로(3,6)을 막으면 탈출지연시간은 2분이다.
// 여러분은 입력 데이터에 표시된 도로망을 읽고, 경찰이 한 도로를 막고 검문함으로써 지연시킬 수 있는 최대시간을 정수로 출력하여야한다. 만일 지연효과가 없으면 0을 출력해야하고, 도시를 빠져나가지 못하게 만들 수 있으면(지연시간이 무한대) -1을 출력해야 한다.
//
// - 입력
// 첫 줄에는 지점의 수를 나타내는 정수 N(6 ≤ N ≤ 1000)과 도로의 수 M(6 ≤ M ≤ 5000)이 주어진다. 그 다음 이어 나오는 M개의 각 줄에는 도로(a, b)와 그 통과시간 t가 a b t 로 표시된다. 단 이 경우 a < b 이고 1 ≤ t ≤ 10000이다.
//
// - 출력
// 경찰이 하나의 도로를 막음으로써 지연시킬 수 있는 최대 시간을 정수로 출력한다. (단, 그 지연시간이 무한대이면 -1을 출력해야 한다.)

#include <bits/stdc++.h>
using namespace std;

#define INF 50000000001

int N, M;
vector<pair<int, long long>> graph[1001];
vector<long long> dist(1001, INF);
vector<int> visited(1001, 0), bef(1001, -1);
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

void init() {
  for (int i = 1; i <= N; i++) {
    visited[i] = 0;
    dist[i] = INF;
  }
}

long long dijkstra(int s, int e) {
  init();
  dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    int curr;
    do {
      curr = pq.top().second;
      pq.pop();
    } while (!pq.empty() && visited[curr]);
    if (visited[curr])
      break;
    visited[curr] = 1;
    for (auto &p : graph[curr]) {
      int next = p.first;
      long long d = p.second;
      if (dist[next] > dist[curr] + d) {
        dist[next] = dist[curr] + d;
        bef[next] = curr;
        pq.push({dist[next], next});
      }
    }
  }
  return dist[e];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  while (M--) {
    int a, b, t;
    cin >> a >> b >> t;
    graph[a].push_back({b, t});
    graph[b].push_back({a, t});
  }
  long long m = dijkstra(1, N), ans = -1;
  int tmp = N;
  vector<int> way;
  while (tmp > 0) {
    way.push_back(tmp);
    tmp = bef[tmp];
  }
  for (int i = 0; i < way.size() - 1; i++) {
    int a = way[i], b = way[i + 1];
    int a_idx, b_idx, a_cost, b_cost;
    for (int j = 0; j < graph[a].size(); j++)
      if (graph[a][j].first == b) {
        a_idx = j;
        a_cost = graph[a][j].second;
        graph[a][j].second = INF;
        break;
      }
    for (int j = 0; j < graph[b].size(); j++)
      if (graph[b][j].first == a) {
        b_idx = j;
        b_cost = graph[b][j].second;
        graph[b][j].second = INF;
        break;
      }
    long long time = dijkstra(1, N);
    if (time == INF) {
      ans = -1;
      break;
    }
    long long gap = time - m;
    ans = max(ans, gap);
    graph[a][a_idx].second = a_cost;
    graph[b][b_idx].second = b_cost;
  }
  cout << ans << '\n';
  return 0;
}