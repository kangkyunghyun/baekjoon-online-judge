// 27277: 장기자랑
//
// - 문제
// 즐거운 설날을 맞아 부대 장기자랑 행사가 개최된다! 이 행사는 한 번에 한 명씩 순서대로 공연하는 형식으로 진행된다.
// 장기자랑 행사의 총관리자는 공연하는 병사들의 장기자랑 실력을 토대로 행사를 준비하던 중, 아무래도 앞에 공연한 사람이 너무 잘하면 뒤에 공연하는 사람이 부담감을 느껴 본 실력을 발휘하지 못할 것이라는 고민을 하게 되었다. 이에 총관리자는 각 병사의 장기자랑 실력을 순서대로 a_1, a_2, \cdots, a_n이라고 할 때, 2≤ i≤ N에 대하여 i번째 공연자는 실력을 \max\left(0,a_i-a_{i-1}\right)만큼만 발휘할 수 있을 것이라는 가설을 세웠다. 이때, 가장 먼저 공연하는 병사는 본인의 실력을 그대로 발휘할 수 있다.
// 위 가설에 따라, 총관리자는 병사들이 발휘할 수 있는 실력의 합이 최대가 되게끔 공연순서를 배치하고자 한다. 적절한 순서로 병사들을 배치했을 때, 각 병사가 발휘할 수 있는 실력의 합의 최댓값을 구하여라.
//
// - 입력
// 첫 번째 줄에 병사의 수 N이 주어진다. (1 ≤ N ≤ 100,000)
// 두 번째 줄에 N명의 병사들의 장기자랑 실력을 나타내는 정수 a_i가 공백으로 구분되어 주어진다. (1 ≤ a_i ≤ 10,000) 
//
// - 출력
// 적절한 순서로 N명의 병사들을 배치했을 때, 각 병사가 발휘할 수 있는 실력의 합의 최댓값을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, ans = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  vector<int> result;
  if (n % 2) {
    for (int i = 0; i < n / 2; i++) {
      result.push_back(v[n - i - 1]);
      result.push_back(v[i]);
    }
    result.push_back(v[n / 2]);
  } else {
    for (int i = 0; i < n / 2; i++) {
      result.push_back(v[n - i - 1]);
      result.push_back(v[i]);
    }
  }
  ans += result[0];
  for (int i = 1; i < n; i++)
    ans += max(0, result[i] - result[i - 1]);
  cout << ans;
  return 0;
}