// 4792: 레드 블루 스패닝 트리
//
// - 문제
// 무방향, 무가중치, 연결 그래프가 주어진다. 그래프의 각 간선은 빨간색 또는 파란색으로 색칠되어져 있다. 이 그래프의 스패닝 트리 중 파란색 간선이 정확히 k개인 것이 있는지 없는지 알아내는 프로그램을 작성하시오.
//
// - 입력
// 입력은 여러 개의 테스트 케이스로 이루어져 있다.
// 각 테스트 케이스의 첫 줄에는 세 정수 n, m, k가 주어진다. n은 그래프의 정점의 개수 (2 ≤ n ≤ 1,000)이고, m은 간선의 개수, k는 문제에 설명되어 있는 파란색 간선의 개수 (0 ≤ k < n) 이다.
// 다음 m개 줄에는 간선의 정보가 주어지며, 각 정보는 세 정수 c, f, t로 이루어져 있다. c는 간선의 색상을 나타내며, 빨간색인 경우에는 R, 파란색인 경우에는 B이다. f와 t는 정수로 간선이 연결하는 두 정점을 나타낸다. (1 ≤ f, t ≤ n, f ≠ t) 두 정점을 연결하는 간선은 최대 한 개이다.
// 입력의 마지막 줄에는 0이 세 개 주어진다.
//
// - 출력
// 각 테스트 케이스마다 파란색 간선이 정확하게 k개인 스패닝 트리를 만들 수 있으면 1, 없으면 0을 출력한다.

#include <bits/stdc++.h>
using namespace std;

vector<int> p;
vector<pair<int, pair<int, int>>> edge;

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

int kruskal() {
  iota(p.begin(), p.end(), 0);
  int cnt = 0;
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      cnt += weight;
      merge(path.first, path.second);
    }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n + m + k == 0)
      break;
    p.resize(n + 1);
    edge.clear();
    while (m--) {
      char c;
      int f, t;
      cin >> c >> f >> t;
      if (c == 'B')
        edge.push_back({1, {f, t}});
      else
        edge.push_back({0, {f, t}});
    }
    sort(edge.begin(), edge.end());
    int minBlue = kruskal();
    sort(edge.begin(), edge.end(), greater<>());
    int maxBlue = kruskal();
    if (minBlue <= k && k <= maxBlue)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}