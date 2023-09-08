// 24516: 잘 알려진 수열 구하기
//
// - 문제
// 다음 두 조건에 맞는 길이가 N인 수열을 아무거나 하나 구해서 출력해보자.
// 수열의 모든 원소는 서로 다르고, 수열의 원소는 1 이상 100,000 이하인 정수다.
// 수열의 연속한 부분 수열 중에, 길이가 k인 모든 연속한 부분 수열의 합은 k로 나누어떨어진다.
//
// - 입력
// 첫째 줄에 수열의 길이 N(1 ≤ N ≤ 5,000)이 주어진다.
//
// - 출력
// 첫째 줄에 문제 조건에 맞는 길이 N인 수열을 아무거나 하나 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, x = 2;
  cin >> n;
  while (n--) {
    cout << x << ' ';
    x += 2;
  }
  return 0;
}