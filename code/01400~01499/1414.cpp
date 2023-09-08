// 1414: 불우이웃돕기
//
// - 문제
// 다솜이는 불우이웃 돕기 활동을 하기 위해 무엇을 할지 생각했다. 마침 집에 엄청나게 많은 랜선이 있다는 것을 깨달았다. 마침 랜선이 이렇게 많이 필요 없다고 느낀 다솜이는 랜선을 지역사회에 봉사하기로 했다.
// 다솜이의 집에는 N개의 방이 있다. 각각의 방에는 모두 한 개의 컴퓨터가 있다. 각각의 컴퓨터는 랜선으로 연결되어 있다. 어떤 컴퓨터 A와 컴퓨터 B가 있을 때, A와 B가 서로 랜선으로 연결되어 있거나, 또 다른 컴퓨터를 통해서 연결이 되어있으면 서로 통신을 할 수 있다.
// 다솜이는 집 안에 있는 N개의 컴퓨터를 모두 서로 연결되게 하고 싶다.
// N개의 컴퓨터가 서로 연결되어 있는 랜선의 길이가 주어질 때, 다솜이가 기부할 수 있는 랜선의 길이의 최댓값을 출력하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 컴퓨터의 개수 N이 주어진다. 둘째 줄부터 랜선의 길이가 주어진다. i번째 줄의 j번째 문자가 0인 경우는 컴퓨터 i와 컴퓨터 j를 연결하는 랜선이 없음을 의미한다. 그 외의 경우는 랜선의 길이를 의미한다. 랜선의 길이는 a부터 z는 1부터 26을 나타내고, A부터 Z는 27부터 52를 나타낸다. N은 50보다 작거나 같은 자연수이다.
//
// - 출력
// 첫째 줄에 다솜이가 기부할 수 있는 랜선의 길이의 최댓값을 출력한다. 만약, 모든 컴퓨터가 연결되어 있지 않으면 -1을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int N, cost = 0;
vector<pair<int, pair<int, int>>> edge;
vector<int> p;

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
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  p.resize(N + 1);
  iota(p.begin(), p.end(), 0);
  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= N; j++)
      if (s[j - 1] != '0') {
        if (s[j - 1] >= 'a') {
          edge.push_back({s[j - 1] - 'a' + 1, {i, j}});
          cost += s[j - 1] - 'a' + 1;
        } else {
          edge.push_back({s[j - 1] - 'A' + 27, {i, j}});
          cost += s[j - 1] - 'A' + 27;
        }
      }
  }
  sort(edge.begin(), edge.end());
  for (auto [weight, path] : edge)
    if (find(path.first) != find(path.second)) {
      cost -= weight;
      merge(path.first, path.second);
    }
  for (int i = 1; i <= N; i++)
    find(i);
  if (accumulate(p.begin(), p.end(), 0) != N)
    cout << -1;
  else
    cout << cost;
  return 0;
}