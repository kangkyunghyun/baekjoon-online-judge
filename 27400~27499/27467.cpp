// 27467: 수학 퀴즈
//
// - 문제
// 에릭은 KSA 신입생들을 대상으로 수학 퀴즈를 내려고 한다. 정확히는 자신의 숙제를 깔끔하게 해결하기 위해 신입생들에게 수학 식의 항 개수를 줄이게 하려고 한다.
// 이차방정식 x^2 + x + 1 = 0의 한 복소근을 \omega라고 할 때, N개의 정수 A_1, A_2, \cdots, A_N이 주어지면 다음 등식을 만족하는 두 실수 p, q를 구하면 된다.
// \sum_{k=1}^N \omega^{A_k} = \omega^{A_1} + \omega^{A_2} + \cdots + \omega^{A_N} = p\omega + q
// KSA 신입생들 대신에 위 퀴즈를 해결해보자!
//
// - 입력
// 첫 번째 줄에 정수 N이 주어진다.
// 두 번째 줄에는 N개의 정수 A_1, A_2, \cdots, A_N이 주어진다.
//
// - 출력
// 문제에서 설명한 두 실수 p, q를 출력한다. 단, 정답과의 절대/상대 오차는 10^{-9}까지 허용한다.
//
// - 제한
//  2 ≤ N ≤ 3 × 10^5 
//  0 ≤ A_i ≤ 10^9 

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  double p = 0, q = 0;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    if (x > 3) {
      x %= 3;
    }
    if (x == 1) {
      p++;
    } else if (x == 2) {
      p--;
      q--;
    } else {
      q++;
    }
  }
  cout.precision(10);
  cout << fixed << p << ' ' << q << '\n';
  return 0;
}