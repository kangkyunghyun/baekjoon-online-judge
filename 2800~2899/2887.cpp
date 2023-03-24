// 2887: 행성 터널
//
// - 문제
// 때는 2040년, 이민혁은 우주에 자신만의 왕국을 만들었다. 왕국은 N개의 행성으로 이루어져 있다. 민혁이는 이 행성을 효율적으로 지배하기 위해서 행성을 연결하는 터널을 만들려고 한다.
// 행성은 3차원 좌표위의 한 점으로 생각하면 된다. 두 행성 A(xA, yA, zA)와 B(xB, yB, zB)를 터널로 연결할 때 드는 비용은 min(|xA-xB|, |yA-yB|, |zA-zB|)이다.
// 민혁이는 터널을 총 N-1개 건설해서 모든 행성이 서로 연결되게 하려고 한다. 이때, 모든 행성을 터널로 연결하는데 필요한 최소 비용을 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 행성의 개수 N이 주어진다. (1 ≤ N ≤ 100,000) 다음 N개 줄에는 각 행성의 x, y, z좌표가 주어진다. 좌표는 -109보다 크거나 같고, 109보다 작거나 같은 정수이다. 한 위치에 행성이 두 개 이상 있는 경우는 없다.
//
// - 출력
// 첫째 줄에 모든 행성을 터널로 연결하는데 필요한 최소 비용을 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int N;
vector<pii> graph[100001];

int prim() {
  priority_queue<pii> pq;
  vector<int> visited(N + 1, 0);
  visited[1] = 1;
  for (pii edge : graph[1])
    pq.push(edge);
  int cost = 0, cnt = 1;
  while (cnt < N) {
    auto [weight, node] = pq.top();
    pq.pop();
    if (!visited[node]) {
      visited[node] = 1;
      cost -= weight;
      cnt++;
      for (pii next : graph[node])
        if (!visited[next.second])
          pq.push(next);
    }
  }
  return cost;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  vector<pair<int, int>> x, y, z;
  for (int i = 1; i <= N; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    x.push_back({a, i});
    y.push_back({b, i});
    z.push_back({c, i});
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  sort(z.begin(), z.end());
  for (int i = 0; i < N - 1; i++) {
    graph[x[i].second].push_back({-abs(x[i].first - x[i + 1].first), x[i + 1].second});
    graph[x[i + 1].second].push_back({-abs(x[i].first - x[i + 1].first), x[i].second});
    graph[y[i].second].push_back({-abs(y[i].first - y[i + 1].first), y[i + 1].second});
    graph[y[i + 1].second].push_back({-abs(y[i].first - y[i + 1].first), y[i].second});
    graph[z[i].second].push_back({-abs(z[i].first - z[i + 1].first), z[i + 1].second});
    graph[z[i + 1].second].push_back({-abs(z[i].first - z[i + 1].first), z[i].second});
  }
  cout << prim();
  return 0;
}