// 9694: 무엇을 아느냐가 아니라 누구를 아느냐가 문제다
//
// - 문제
// 한신이는 젊고, 똑똑하고 매우 유명한 정치인이다. 그럼에도 그는 여전히 자신의 성공을 위해서도 인간관계는 중요한것이라고 믿고있다. 다음달에 열릴 국회의원선거에서 한신이는 자신의 당이 반드시 이기길 희망한다. 그러기 위해서 최고의원의 지지가 필요하다.
// 이 최고의원의 지지를 받기위해 한신이는 전략을 세웠다. 그는 그 최고의원을 직접적으로 만날수 없다면 그를 알고있는 인맥을 이용하여 만날것이다. 이것을 위해서 우선 정치인들의 친밀도를 조사하였는데 친밀도를 다음 4단계로 나누어서 기록해놓았다.
// 최측근 [1] / 측근 [2] / 비즈니스관계 [3] / 지인 [4]
// [두 사람의 관계는 이 4가지 경우중 반드시 해당되며, 적(enemy)는 존재하지 않는다.]
// 한신이는 지인보다는 최측근 친구에게 소개받기 원한다. 그래서 최고의원을 만나기까지의 인맥간 친밀도의 합을 최소화하고 싶어한다.
// N명의 정치인 명단으로부터 그들의 인맥 친밀도가 주어진다. 정치인 리스트를 보고 한신이가 최고의원을 만나기까지의 친밀도의 합 중에서 가장 작은 값을 구하면 된다.
//
// - 입력
// 맨위 첫 번째 줄에 T(1 <T< 100)는 테스트케이스 수를 의미한다. 이것을 따라 다음줄에 각 테스트 케이스가 주어지는데, 첫 번째 줄에는 N과 M이 주어진다. N(N ≤ 20)은 관계의 개수를 의미하며, M(5 ≤M≤ 20)은 정치인의 수를 나타낸다. 이 다음 N줄에는 정치인 x, 그의 친구 y (0 ≤x,y< M), 두사람간의 친밀도 z(1 ≤z≤ 4)를 입력받는다. 정치인 0번은 한신이를 나타내고 M-1은 최고의원을 의미한다.
//
// - 출력
// 각 테스트 케이스는 "Case #x: "의 형식으로 출력되며 x는 케이스 번호(1부터 시작)을 의미한다. 콜론뒤에 한신이가 최고의원을 만날수 있다면 0번 정치인(한신이)를 시작으로 M-1번 정치인(최고의원)까지 만난 순서대로 출력하면 되고, 최고의원을 만날수 없는 경우엔 -1을 출력하면 된다.

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int T, N, M;
vector<pair<int, int>> graph[20];
vector<int> dist(20, INF), visited(20, 0), bef(20, -1);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void init() {
  for (int i = 0; i < M; i++) {
    graph[i].clear();
    visited[i] = 0;
    bef[i] = -1;
    dist[i] = INF;
  }
}

int dijkstra(int s, int e) {
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
      int next = p.first, d = p.second;
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
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> N >> M;
    init();
    while (N--) {
      int x, y, z;
      cin >> x >> y >> z;
      graph[x].push_back({y, z});
      graph[y].push_back({x, z});
    }
    cout << "Case #" << i << ": ";
    if (dijkstra(0, M - 1) == INF) {
      cout << -1;
    } else {
      vector<int> way;
      int tmp = M - 1;
      while (tmp >= 0) {
        way.push_back(tmp);
        tmp = bef[tmp];
      }
      for (int i = way.size() - 1; i >= 0; i--)
        cout << way[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}