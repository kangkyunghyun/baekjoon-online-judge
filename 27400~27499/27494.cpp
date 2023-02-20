// 27494: 2023년은 검은 토끼의 해
//
// - 문제
// 2023년은 검은 토끼의 해로 불린다. 스타는 검은 토끼의 해를 기념해서 흑묘 복권을 만들려고 한다.
// 흑묘 복권은 총 N개의 티켓으로 구성된다. 각 티켓에는 1 이상 N 이하의 정수인 시리얼 번호가 적혀 있으며 서로 다른 티켓에는 서로 다른 시리얼 번호가 적혀있다.
// 티켓 중에서 시리얼 번호가 네 자릿수 이상이고 서로 다른 자리에서 네 개의 자릿수를 골라 고른 자릿수를 제외한 나머지 자릿수를 지울 때 2023을 만들 수 있으면 해당 티켓은 당첨 티켓이다. 예를 들어 시리얼 번호가 2023, 1280423, 2200233이면 당첨이고 3480, 572, 2032이면 꽝이다.
// N이 주어졌을 때, 흑묘 복권의 당첨 티켓 수를 구하여라
//
// - 입력
// 흑묘 복권의 티켓 수 N이 주어진다. (1 ≤ N ≤ 10,000,000)
//
// - 출력
// 당첨 티켓 수를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, ans = 0;
  cin >> n;
  for (int i = 2023; i <= n; i++) {
    string num = to_string(i);
    if (num.find('2', 0) != string::npos) {
      int idx = num.find('2', 0);
      if (num.find('0', idx) != string::npos) {
        idx = num.find('0', idx);
        if (num.find('2', idx) != string::npos) {
          idx = num.find('2', idx);
          if (num.find('3', idx) != string::npos)
            ans++;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}