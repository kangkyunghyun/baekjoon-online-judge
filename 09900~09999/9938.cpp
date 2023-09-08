// 9938: 방 청소
//
// - 문제
// 은기는 술병 N개(1부터 N까지 번호가 매겨져 있다)와 서랍 L개(1부터 L까지 번호가 매겨져 있다)를 가지고 있다. 술병은 은기의 방 바닥에 흩어져 있고, 어린이날을 맞이해 방 청소를 하려고 한다.  서랍에는 술병이 하나 들어갈 수 있다. 나중에 원하는 술을 빠르게 찾을 수 있게 하기 위해 은기는 각각의 술병이 들어갈 수 있는 서랍의 번호 Ai와 Bi를 공책에 적어 놓았다.
// 은기는 술병을 1번부터 N번까지 순서대로 정리할 것이고, 각각의 술병에 대해서 다음과 같은 과정을 거친다.
// 1. 서랍 Ai가 비어있다면, i번 술을 그 서랍에 보관한다.
// 2. 서랍 Bi가 비어있다면, i번 술을 그 서랍에 보관한다.
// 3. Ai에 들어있는 술을 다른 서랍으로 이동시킨다.(다른 서랍은 Ai에 들어있는 술이 들어갈 수 있는 서랍 중 하나이다) 만약, 그 서랍에도 이미 술이 들어있다면, 그 술을 다른 서랍으로 이동시킨다. 이런 과정을 거쳐서 빈 서랍을 하나 찾아 술을 모두 이동할 수 있는 경우에는, 술을 이동시키고 i번 술을 Ai에 보관한다. 불가능한 경우에는 다음 규칙으로 넘어간다.
// 4. Bi에 들어있는 술을 다른 서랍으로 이동시킨다. 만약, 그 서랍에도 이미 술이 들어있다면, 그 술을 다른 서랍으로 이동시킨다. 이런 과정을 거쳐서 빈 서랍을 하나 찾아 술을 모두 이동할 수 있는 경우에는, 술을 이동시키고 i번 술을 Bi에 보관한다. 불가능한 경우에는 다음 규칙으로 넘어간다.
// 5. 위의 과정이 모두 불가능한 경우에는 i번 술을 그 자리에서 마셔버린다. (은기는 전혀 취하지 않는다)
// 각각의 술에 대해서, 서랍에 보관할 수 있는지, 그 자리에서 마셔버리는지를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 N과 L이 주어진다. (1 ≤ N, L ≤ 300,000)
// 다음 N개 줄에는 Ai와 Bi가 주어진다. (1 ≤ Ai, Bi ≤ L, Ai ≠ Bi)
//
// - 출력
// 1번 술부터 N번 술까지 순서대로 보관할 수 있는지, 그 자리에서 먹어야 하는지를 출력한다.
// 보관할 수 있는 경우에는 "LADICA"를, 먹어버려야 하는 경우에는 "SMECE"를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<int> p(300001), visited(300001, 0);

int find(int x) {
  if (p[x] != x)
    p[x] = find(p[x]);
  return p[x];
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  p[x] = y;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> L;
  iota(p.begin(), p.end(), 0);
  while (N--) {
    int a, b;
    cin >> a >> b;
    if (!visited[a]) {
      cout << "LADICA\n";
      visited[a] = 1;
      merge(a, b);
    } else if (!visited[b]) {
      cout << "LADICA\n";
      visited[b] = 1;
      merge(b, a);
    } else if (!visited[find(a)]) {
      cout << "LADICA\n";
      visited[find(a)] = 1;
      merge(a, b);
    } else if (!visited[find(b)]) {
      cout << "LADICA\n";
      visited[find(b)] = 1;
      merge(b, a);
    } else {
      cout << "SMECE\n";
    }
  }
  return 0;
}