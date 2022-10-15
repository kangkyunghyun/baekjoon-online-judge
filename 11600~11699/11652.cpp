// 11652: 카드
//
// - 문제
// 준규는 숫자 카드 N장을 가지고 있다. 숫자 카드에는 정수가 하나 적혀있는데, 적혀있는 수는 -2^62보다 크거나 같고, 2^62보다 작거나 같다.
// 준규가 가지고 있는 카드가 주어졌을 때, 가장 많이 가지고 있는 정수를 구하는 프로그램을 작성하시오. 만약, 가장 많이 가지고 있는 정수가 여러 가지라면, 작은 것을 출력한다.
//
// - 입력
// 첫째 줄에 준규가 가지고 있는 숫자 카드의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개 줄에는 숫자 카드에 적혀있는 정수가 주어진다.
//
// - 출력
// 첫째 줄에 준규가 가장 많이 가지고 있는 정수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, cnt = 1, max = 1;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  long long ans = v[0];
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i - 1])
      cnt++;
    else
      cnt = 1;
    if (cnt > max) {
      max = cnt;
      ans = v[i];
    }
  }
  cout << ans;
  return 0;
}