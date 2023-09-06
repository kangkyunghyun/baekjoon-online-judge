// 2162: 선분 그룹
//
// - 문제
// N개의 선분들이 2차원 평면상에 주어져 있다. 선분은 양 끝점의 x, y 좌표로 표현이 된다.
// 두 선분이 서로 만나는 경우에, 두 선분은 같은 그룹에 속한다고 정의하며, 그룹의 크기는 그 그룹에 속한 선분의 개수로 정의한다. 두 선분이 만난다는 것은 선분의 끝점을 스치듯이 만나는 경우도 포함하는 것으로 한다.
// N개의 선분들이 주어졌을 때, 이 선분들은 총 몇 개의 그룹으로 되어 있을까? 또, 가장 크기가 큰 그룹에 속한 선분의 개수는 몇 개일까? 이 두 가지를 구하는 프로그램을 작성해 보자.
//
// - 입력
// 첫째 줄에 N(1 ≤ N ≤ 3,000)이 주어진다. 둘째 줄부터 N+1번째 줄에는 양 끝점의 좌표가 x1, y1, x2, y2의 순서로 주어진다. 각 좌표의 절댓값은 5,000을 넘지 않으며, 입력되는 좌표 사이에는 빈칸이 하나 있다.
//
// - 출력
// 첫째 줄에 그룹의 수를, 둘째 줄에 가장 크기가 큰 그룹에 속한 선분의 개수를 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int n;
vector<pair<pii, pii>> lines;
vector<int> p, cnt;

ll ccw(pii a, pii b, pii c) {
  ll cc = (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
  if (cc > 0)
    return 1;
  else if (cc < 0)
    return -1;
  return 0;
}

bool check(pii a, pii b, pii c, pii d) {
  ll cc1 = ccw(a, b, c) * ccw(a, b, d);
  ll cc2 = ccw(c, d, a) * ccw(c, d, b);
  if (cc1 == 0 && cc2 == 0) {
    if (a > b)
      swap(a, b);
    if (c > d)
      swap(c, d);
    return a <= d && c <= b;
  }
  return cc1 <= 0 && cc2 <= 0;
}

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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  lines.resize(n);
  p.resize(n);
  iota(p.begin(), p.end(), 0);
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    lines[i] = {{x1, y1}, {x2, y2}};
  }
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (check(lines[i].first, lines[i].second, lines[j].first, lines[j].second))
        merge(i, j);
  for (int i = 0; i < n; i++)
    find(i);
  cnt.resize(n, 0);
  for (int i = 0; i < n; i++)
    cnt[p[i]]++;
  int ans1 = 0, ans2 = 0;
  for (int i : cnt)
    if (i) {
      ans1++;
      ans2 = max(ans2, i);
    }
  cout << ans1 << '\n'
       << ans2;
  return 0;
}