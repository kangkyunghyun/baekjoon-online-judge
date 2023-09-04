// 20010: 악덕 영주 혜유
//
// - 문제
// FT온라인 게임에서 치열한 경쟁을 통해 영주가 된 혜유는 퀘스트를 받았다. 퀘스트의 내용은 자신이 관리하고 있는 마을 사이에 교역로를 건설하여 마을 간 교류를 활성화시키는 것이다. 이때, 교역로는 양 방향으로 이동할 수 있으며, 서로 도달이 불가능한 마을이 없도록 교역로를 건설하여야 한다.
// 마음이 괘씸한 혜유는 돈을 최대한 적게 쓰면서 퀘스트를 달성하려고 한다. 혜유를 도와서 모든 마을과 마을을 최소한의 비용으로 연결하고 그 비용을 구해보자. 또한 혜유는 이때 마을과 마을을 이동하는 가장 최악의 비용이 얼마인지에 관심이 많다. 임의의 두 마을을 이동하는 최단 경로 중 비용이 가장 큰 경로의 비용도 구해보자.
//
// - 입력
// 첫 번째 줄에는 마을의 수 N(1 ≤ N ≤ 1,000)과 설치 가능한 교역로의 수 K(1 ≤ K ≤ 1,000,000)가 주어진다.
// 두 번째 줄부터 K + 1줄에는 서로 다른 두 마을의 번호 a, b (a ≠ b)와 두 마을을 연결하는 비용 c가 주어진다. (1 ≤ c ≤ 1,000,000)
// 항상 모든 마을을 연결할 수 있는 경우만 입력으로 주어진다, 또한 최소 비용으로 연결하는 방법은 유일하다.
// 서로 다른 두 마을 사이에 건설할 수 있는 교역로는 최대 하나뿐이다.
// 마을은 0부터 N - 1 사이의 번호를 갖는다.
//
// - 출력
// 첫 번째 줄에는 모든 마을을 연결하는 최소 비용을 출력한다.
// 두 번째 줄에는 마을과 마을을 이동하는 비용이 가장 큰 경로의 비용을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int N, K, mst_weight = 0, M = 0, X;
vector<pair<int, pair<int, int>>> edge;
vector<pair<int, int>> mst[10001];
vector<int> p, visited(10001, 0);

int find(int x) {
  if (p[x] != x)
    p[x] = find(p[x]);
  return p[x];
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x < y)
    p[y] = x;
  else
    p[x] = y;
}

void dfs(int curr, int sum) {
  if (mst[curr].size() == 1 && sum) {
    if (sum > M) {
      M = sum;
      X = curr;
    }
    return;
  }
  for (auto [next, weight] : mst[curr])
    if (!visited[next]) {
      visited[next] = 1;
      dfs(next, sum + weight);
      visited[next] = 0;
    }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  p.resize(N);
  iota(p.begin(), p.end(), 0);
  while (K--) {
    int a, b, c;
    cin >> a >> b >> c;
    edge.push_back({c, {a, b}});
  }
  sort(edge.begin(), edge.end());
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      mst_weight += weight;
      mst[path.first].push_back({path.second, weight});
      mst[path.second].push_back({path.first, weight});
      merge(path.first, path.second);
    }
  cout << mst_weight << '\n';
  visited[1] = 1;
  dfs(1, 0);
  visited[1] = 0;
  M = 0;
  visited[X] = 1;
  dfs(X, 0);
  cout << M;
  return 0;
}