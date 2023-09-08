// 27924: 윤이는 엄청난 것을 훔쳐갔습니다
//
// - 문제
// 윤이는 엄청난 것을 훔쳐 갔다!
// UDP 마을의 경찰인 달구와 포닉스는 윤이를 잡기 위해 출동했다. UDP 마을은 N개의 정점을 가진 트리 구조로 되어 있다. 트리는 N개의 정점과 N-1개의 간선으로 이루어진 연결 그래프이다. 트리에서 이웃한 정점이 하나밖에 없는 정점을 리프 노드라고 부른다.
// 트리의 각 정점에는 1번부터 N번까지 번호가 붙어 있다. 윤이는 정점 a에서 출발하고, 달구와 포닉스는 각각 정점 b, c에서 출발한다. 주어지는 세 정점은 서로 다르다. 윤이, 달구, 포닉스는 다음과 같이 번갈아 이동하며 추격전을 벌인다. 이동 도중 한 정점 위에 둘 이상이 존재해도 된다.
// 먼저 윤이가 간선을 따라 이웃한 정점으로 이동한다.
// 그다음 달구와 포닉스가 각각 간선을 따라 이웃한 정점으로 이동한다.
// 윤이는 경찰과 동일한 정점에 위치하는 즉시 경찰에게 잡힌다. 반면, 윤이가 경찰에게 잡히지 않고 리프 노드에 도달하면 즉시 이웃한 마을로 탈출할 수 있다. 윤이가 리프 노드에서 출발하는 경우도 마찬가지다.
// 윤이, 달구, 포닉스가 최선의 전략으로 추격전을 벌일 때, 윤이는 무사히 탈출할 수 있을까?
//
// - 입력
// 첫 번째 줄에 UDP 마을의 정점 개수 N이 주어진다. (3 ≤ N ≤ 200,000)
// 다음 N-1개의 줄에 트리의 간선 정보를 나타내는 정수 u, v가 주어진다. 정점 u와 v 사이에 간선이 존재함을 나타낸다. (1 ≤ u,v ≤ N)
// 그다음 줄에 윤이, 달구, 포닉스의 위치를 나타내는 정수 a, b, c가 주어진다. (1 ≤ a,b,c ≤ N; a, b, c는 서로 다르다.)
//
// - 출력
// 윤이가 탈출할 수 있으면 YES, 그렇지 않으면 NO를 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> edges[200001];
int av[200001], bv[200001], cv[200001];

void bfs(int x, int visited[]) {
  queue<int> q;
  q.push(x);
  visited[x] = 1;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (int next : edges[curr]) {
      if (!visited[next]) {
        q.push(next);
        visited[next] = visited[curr] + 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  int a, b, c;
  cin >> a >> b >> c;
  bfs(a, av);
  bfs(b, bv);
  bfs(c, cv);
  vector<int> leaf;
  for (int i = 1; i <= n; i++)
    if (edges[i].size() == 1)
      leaf.push_back(i);
  for (int i : leaf) {
    if (av[i] < bv[i] && av[i] < cv[i]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}