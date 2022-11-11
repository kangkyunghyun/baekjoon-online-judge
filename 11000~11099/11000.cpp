// 11000: 강의실 배정
//
// - 문제
// 수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다.
// 김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다.
// 참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다. (즉, Ti ≤ Sj 일 경우 i 수업과 j 수업은 같이 들을 수 있다.)
// 수강신청 대충한 게 찔리면, 선생님을 도와드리자!
//
// - 입력
// 첫 번째 줄에 N이 주어진다. (1 ≤ N ≤ 200,000)
// 이후 N개의 줄에 Si, Ti가 주어진다. (0 ≤ Si < Ti ≤ 10^9)
//
// - 출력
// 강의실의 개수를 출력하라.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    int s, t;
    cin >> s >> t;
    v[i] = make_pair(s, t);
  }
  sort(v.begin(), v.end());
  priority_queue<int, vector<int>, greater<>> pq;
  for (int i = 0; i < n; i++) {
    pq.push(v[i].second);
    if (pq.top() <= v[i].first)
      pq.pop();
  }
  cout << pq.size();
  return 0;
}