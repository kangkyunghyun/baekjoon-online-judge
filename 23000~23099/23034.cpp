// 23034: 조별과제 멈춰!
//
// - 문제
// 교수님이 시험 기간에 조별 과제를 준비하셨다...! 가톨릭대학교의 조교 아리는 N명의 학생을 2개의 조로 구성하여 과제 공지를 하려 한다. 이때, 구성된 각 조의 인원은 1명 이상이어야 한다. 각 학생은 1~N의 정수 중 고유한 번호를 학번으로 갖는다.
// 모든 것이 귀찮은 아리는 각 조의 팀장에게만 공지를 전달한다. 아리는 N명의 학생 사이에 있는 총 M개의 회선의 리스트를 가지고 있다. 리스트에는 각 회선에 연결된 두 학생의 학번 A와 B, 연락에 필요한 비용 C가 적혀있다. 회선이 연결된 두 학생은 서로 연락이 가능하다. 아리가 각 팀장에게 공지를 전달하면, 각 팀장과 공지를 알게 된 팀원은 같은 조의 모든 팀원에게 공지 내용을 회선을 통해서만 전달한다. 어떤 학생이 팀장이 되어도 모든 학생은 공지 내용을 전달받을 수 있다.
// 아리는 공지 채팅방을 만들 생각은 안 하고, 모든 학생이 공지 내용을 알게 될 때까지 학생들이 연락하며 소요되는 비용의 총합 T의 최솟값을 알고 싶어졌다. 그것을 구하여 팀장을 정한 뒤 조를 구성하려고 한다.
// 아리는 다음과 같은 Q개의 질문을 한다.
// X Y : X와 Y가 팀장일 때, T의 최솟값은 무엇인가?
// Q개의 질문에 답할 수 있는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 두 정수 N(2 ≤ N ≤ 1,000), M(N ≤ M ≤ 100,000)가 주어진다.
// 다음 줄부터 M개의 줄에 세 정수 A(1 ≤ A ≤ N), B(1 ≤ B ≤ N), C(1 ≤ C ≤ 100,000)가 주어진다. A와 B가 같은 경우는 주어지지 않으며, 두 학생에 대한 회선은 여러 개가 주어지지 않는다.
// 다음 줄에 Q(1 ≤ Q ≤ 10,000)가 주어진다.
// 다음 줄부터 Q개의 줄에 두 정수 X(1 ≤ X ≤ N), Y(1 ≤ Y ≤ N)가 주어진다. X와 Y가 같은 경우는 주어지지 않는다.
//
// - 출력
// Q개의 질문에 대한 T의 최솟값을 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define piii pair<int, pii>

int V, E, Q;
vector<piii> edges[1001];
vector<pii> mst_edges[1001];
vector<vector<int>> dist(1001, vector<int>(1001, -1));

int prim() {
  priority_queue<piii> pq;
  vector<int> visited(V + 1, 0);
  visited[1] = 1;
  for (piii edge : edges[1])
    pq.push(edge);
  int cost = 0, cnt = 1;
  while (cnt < V) {
    int weight = -pq.top().first;
    int node = pq.top().second.first;
    int curr = pq.top().second.second;
    pq.pop();
    if (!visited[node]) {
      visited[node] = 1;
      cost += weight;
      cnt++;
      mst_edges[curr].push_back({node, weight});
      mst_edges[node].push_back({curr, weight});
      for (piii next : edges[node])
        if (!visited[next.second.first])
          pq.push(next);
    }
  }
  return cost;
}

void bfs(int s) {
  queue<pii> q;
  dist[s][s] = 0;
  q.push({s, 0});
  while (!q.empty()) {
    auto [curr, maxWeight] = q.front();
    q.pop();
    for (auto [next, weight] : mst_edges[curr])
      if (dist[s][next] == -1) {
        int tmp = max(maxWeight, weight);
        dist[s][next] = tmp;
        q.push({next, tmp});
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
    edges[a].push_back({-c, {b, a}});
    edges[b].push_back({-c, {a, b}});
  }
  int mst = prim();
  for (int i = 1; i <= V; i++)
    bfs(i);
  cin >> Q;
  while (Q--) {
    int X, Y;
    cin >> X >> Y;
    cout << mst - dist[X][Y] << '\n';
  }
  return 0;
}