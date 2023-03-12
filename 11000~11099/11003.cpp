// 11003: 최솟값 찾기
//
// - 문제
// N개의 수 A1, A2, ..., AN과 L이 주어진다.
// Di = Ai-L+1 ~ Ai 중의 최솟값이라고 할 때, D에 저장된 수를 출력하는 프로그램을 작성하시오. 이때, i ≤ 0 인 Ai는 무시하고 D를 구해야 한다.
//
// - 입력
// 첫째 줄에 N과 L이 주어진다. (1 ≤ L ≤ N ≤ 5,000,000)
// 둘째 줄에는 N개의 수 Ai가 주어진다. (-109 ≤ Ai ≤ 109)
//
// - 출력
// 첫째 줄에 Di를 공백으로 구분하여 순서대로 출력한다.

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, x;
  cin >> n >> l;
  priority_queue<pair<int, int>> pq;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    pq.push({-x, i});
    while (pq.top().second <= i - l)
      pq.pop();
    cout << -pq.top().first << ' ';
  }
}