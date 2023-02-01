// 13904: 과제
//
// - 문제
// 웅찬이는 과제가 많다. 하루에 한 과제를 끝낼 수 있는데, 과제마다 마감일이 있으므로 모든 과제를 끝내지 못할 수도 있다. 과제마다 끝냈을 때 얻을 수 있는 점수가 있는데, 마감일이 지난 과제는 점수를 받을 수 없다.
// 웅찬이는 가장 점수를 많이 받을 수 있도록 과제를 수행하고 싶다. 웅찬이를 도와 얻을 수 있는 점수의 최댓값을 구하시오.
//
// - 입력
// 첫 줄에 정수 N (1 ≤ N ≤ 1,000)이 주어진다.
// 다음 줄부터 N개의 줄에는 각각 두 정수 d (1 ≤ d ≤ 1,000)와 w (1 ≤ w ≤ 100)가 주어진다. d는 과제 마감일까지 남은 일수를 의미하며, w는 과제의 점수를 의미한다.
//
// - 출력
// 얻을 수 있는 점수의 최댓값을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int d, p;
    cin >> d >> p;
    v.push_back({d, p});
  }
  sort(v.begin(), v.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++) {
    int day = v[i].first;
    int point = v[i].second;
    pq.push(point);
    if (pq.size() > day)
      pq.pop();
  }
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans;
  return 0;
}