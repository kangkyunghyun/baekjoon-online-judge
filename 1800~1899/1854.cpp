// 1854: K번째 최단경로 찾기
//
// - 문제
// 봄캠프를 마친 김진영 조교는 여러 도시를 돌며 여행을 다닐 계획이다. 그런데 김 조교는, '느림의 미학'을 중요시하는 사람이라 항상 최단경로로만 이동하는 것은 별로 좋아하지 않는다. 하지만 너무 시간이 오래 걸리는 경로도 그리 매력적인 것만은 아니어서, 적당한 타협안인 'k번째 최단경로'를 구하길 원한다. 그를 돕기 위한 프로그램을 작성해 보자.
//
// - 입력
// 첫째 줄에 n, m, k가 주어진다. (1 ≤ n ≤ 1000, 0 ≤ m ≤ 2000000, 1 ≤ k ≤ 100) n과 m은 각각 김 조교가 여행을 고려하고 있는 도시들의 개수와, 도시 간에 존재하는 도로의 수이다.
// 이어지는 m개의 줄에는 각각 도로의 정보를 제공하는 세 개의 정수 a, b, c가 포함되어 있다. 이것은 a번 도시에서 b번 도시로 갈 때는 c의 시간이 걸린다는 의미이다. (1 ≤ a, b ≤ n. 1 ≤ c ≤ 1000)
// 도시의 번호는 1번부터 n번까지 연속하여 붙어 있으며, 1번 도시는 시작도시이다.
//
// - 출력
// n개의 줄을 출력한다. i번째 줄에 1번 도시에서 i번 도시로 가는 k번째 최단경로의 소요시간을 출력한다.
// 경로의 소요시간은 경로 위에 있는 도로들을 따라 이동하는데 필요한 시간들의 합이다. i번 도시에서 i번 도시로 가는 최단경로는 0이지만, 일반적인 k번째 최단경로는 0이 아닐 수 있음에 유의한다. 또, k번째 최단경로가 존재하지 않으면 -1을 출력한다. 최단경로에 같은 정점이 여러 번 포함되어도 된다.

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int V, E, K;
  vector<pii> graph[1001];
  cin >> V >> E >> K;
  while (E--) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  priority_queue<int> h[1001];
  priority_queue<pii> pq;
  h[1].push(0);
  pq.push({0, 1});
  while (!pq.empty()) {
    int cost = -pq.top().first;
    int curr = pq.top().second;
    pq.pop();
    for (pii p : graph[curr]) {
      int next = p.first, d = cost + p.second;
      if (h[next].size() < K) {
        h[next].push(d);
        pq.push({-d, next});
      } else if (h[next].top() > d) {
        h[next].pop();
        h[next].push(d);
        pq.push({-d, next});
      }
    }
  }
  for (int i = 1; i <= V; i++)
    cout << (h[i].size() < K ? -1 : h[i].top()) << '\n';
  return 0;
}