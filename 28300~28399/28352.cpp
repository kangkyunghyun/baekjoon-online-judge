// 28352: 10!
//
// - 문제
// $10!$초는 정확히 $6$주와 같다. $10!$초는 $1\times 2\times 3\times \cdots \times 9\times 10 = 3\,628\,800$초이고, $6$주도 $7\times 6\times 24\times 60\times 60 = 3\,628\,800$초이기 때문이다.
// $N!=1\times 2\times 3\times \cdots \times (N-1)\times N$초는 몇 주인지 구하는 프로그램을 작성해 보자.
//
// - 입력
// 첫째 줄에 정수 $N$이 주어진다. $(10 \leq N \leq 17)$ 
//
// - 출력
// $N!$초가 몇 주와 동일한지 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, a = 1;
  cin >> n;
  for (int i = 1; i <= n; i++)
    a *= i;
  cout << a / (7 * 24 * 60 * 60);
  return 0;
}