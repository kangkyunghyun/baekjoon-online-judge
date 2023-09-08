// 13913: 숨바꼭질 4
//
// - 문제
// 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
// 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.
//
// - 출력
// 첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
// 둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> visited(100001, 0), bef(100001, -1);

void bfs(int start) {
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int x = q.front();
    if (x == k)
      break;
    q.pop();
    if (x + 1 >= 0 && x + 1 <= 100000)
      if (!visited[x + 1]) {
        q.push(x + 1);
        visited[x + 1] = visited[x] + 1;
        bef[x + 1] = x;
      }
    if (x - 1 >= 0 && x - 1 <= 100000)
      if (!visited[x - 1]) {
        q.push(x - 1);
        visited[x - 1] = visited[x] + 1;
        bef[x - 1] = x;
      }
    if (x * 2 >= 0 && x * 2 <= 100000)
      if (!visited[x * 2]) {
        q.push(x * 2);
        visited[x * 2] = visited[x] + 1;
        bef[x * 2] = x;
      }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  bfs(n);
  cout << visited[k] << '\n';
  int tmp = k;
  vector<int> ans;
  while (tmp != n) {
    ans.push_back(tmp);
    tmp = bef[tmp];
  }
  ans.push_back(tmp);
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}