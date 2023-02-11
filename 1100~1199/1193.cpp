// 1193: 분수찾기
//
// - 문제
// 1/1	1/2	1/3	1/4	1/5	 …
// 2/1	2/2	2/3	2/4	 …	 …
// 3/1	3/2	3/3	 …	 …	 …
// 4/1	4/2  …	 …	 …	 …
// 5/1	 …	 …	 …	 …	 …
//  …	 …	 …	 …	 …	 …
//
// 이와 같이 나열된 분수들을 1/1 → 1/2 → 2/1 → 3/1 → 2/2 → … 과 같은 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.
// X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 X(1 ≤ X ≤ 10,000,000)가 주어진다.
//
// - 출력
// 첫째 줄에 분수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x, line = 1;
  cin >> x;
  while (x > line) {
    x -= line;
    line++;
  }
  if (line % 2)
    cout << line - x + 1 << '/' << x << '\n';
  else
    cout << x << '/' << line - x + 1 << '\n';
  return 0;
}