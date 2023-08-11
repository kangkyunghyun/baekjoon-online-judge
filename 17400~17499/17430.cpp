// 17430: 가로등
//
// - 문제
// 2차원 공간 위에 가로등이 N개 배치되어 있다. i번째 가로등의 위치는 (xi, yi)이고, 각 좌표는 정수이다. 서로 다른 가로등의 위치가 같은 경우는 없다.
// 두 가로등 i와 j(i < j)가 있을 때, (xi, yj)와 (xj, yi)에 가로등이 있으면, 가로등 i와 j는 균형이 잡혀있다고 한다. 모든 가로등 쌍이 균형잡혀 있는지 아닌지 구해보자.
//
// - 입력
// 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
// 각 테스트 케이스의 첫째 줄에는 가로등의 수 N이 주어지고, 다음 N개의 줄에 걸쳐서 가로등의 위치 xi, yi가 공백으로 구분해 주어진다.
//
// - 출력
// 각 테스트 케이스에 대해서, 모든 가로등의 쌍이 균형 잡혀 있으면 "BALANCED", 아니면 "NOT BALANCED"를 한 줄에 출력한다.
//
// - 제한
// 1 ≤ T ≤ 5
// 2 ≤ N ≤ 200,000
// -10^9 ≤ xi, yi ≤ 10^9

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, flag = 0;
    cin >> n;
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      m[x].push_back(y);
    }
    for (auto &i : m)
      sort(i.second.begin(), i.second.end());
    for (auto i : m) {
      if (flag)
        break;
      for (auto j : m) {
        if (i.first == j.first)
          continue;
        if (i.second != j.second) {
          flag = 1;
          break;
        }
      }
    }
    cout << (flag ? "NOT BALANCED\n" : "BALANCED\n");
  }
  return 0;
}