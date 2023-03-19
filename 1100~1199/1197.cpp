// 1197: 최소 스패닝 트리
//
// - 문제
// 그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.
// 최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.
//
// - 입력
// 첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.
// 그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다. 최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.
//
// - 출력
// 첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define p pair<int, int>

int V, E, visited[10001] = {0}, ans = 0;
vector<p> graph[10001];

void mst() {
  priority_queue<p> pq;
  for (int i = 0; i < graph[1].size(); i++)
    pq.push(graph[1][i]);
  visited[1] = 1;
  int cnt = 0;
  while (cnt < V - 1) {
    int cost = -pq.top().first;
    int node = pq.top().second;
    pq.pop();
    if (!visited[node]) {
      visited[node] = ++cnt;
      ans += cost;
      for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i].second;
        if (!visited[next])
          pq.push(graph[node][i]);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> V >> E;
  while (E--) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back({-c, b});
    graph[b].push_back({-c, a});
  }
  mst();
  cout << ans;
  return 0;
}