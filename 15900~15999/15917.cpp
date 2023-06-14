// 15917: 노솔브 방지문제야!!
//
// - 문제
// 여러분은 Q개의 쿼리를 수행해야 합니다. 수행해야 하는 쿼리는 다음과 같습니다.
// 어떤 수 a를 2의 거듭제곱 꼴로 나타낼 수 있는가?
//
// - 입력
// 첫 줄에 Q가 주어집니다. (1 ≤ Q ≤ 10^6)
// 두 번째 줄부터 Q+1번째 줄까지 a가 주어집니다. a는 1이상 2^31-1이하 자연수입니다.
//
// - 출력
// 각 쿼리마다, 답이 Yes이면 1을, 그렇지 않으면 0을 출력합니다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q, a;
  cin >> q;
  while (q--) {
    cin >> a;
    cout << (log2(a) == (int)log2(a)) << '\n';
  }
  return 0;
}