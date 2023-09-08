// 11728: 배열 합치기
//
// - 문제
// 정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.
//
// - 입력
// 한첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)
// 둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.
//
// - 출력
// 첫째 줄에 두 배열을 합친 후 정렬한 결과를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a[2000001];
  for (int i = 0; i < n + m; i++)
    cin >> a[i];
  sort(a, a + n + m);
  for (int i = 0; i < n + m; i++)
    cout << a[i] << " ";
  cout << '\n';
  return 0;
}