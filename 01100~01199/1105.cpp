// 1105: 팔
//
// - 문제
// L과 R이 주어진다. 이때, L보다 크거나 같고, R보다 작거나 같은 자연수 중에 8이 가장 적게 들어있는 수에 들어있는 8의 개수를 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 L과 R이 주어진다. L은 2,000,000,000보다 작거나 같은 자연수이고, R은 L보다 크거나 같고, 2,000,000,000보다 작거나 같은 자연수이다.
//
// - 출력
// 첫째 줄에 L보다 크거나 같고, R보다 작거나 같은 자연수 중에 8이 가장 적게 들어있는 수에 들어있는 8의 개수를 구하는 프로그램을 작성하시오.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string l, r;
  cin >> l >> r;
  if (l.size() != r.size()) {
    cout << 0;
    return 0;
  }
  int cnt = 0;
  for (int i = 0; i < l.size(); i++)
    if (l[i] == r[i]) {
      if (l[i] == '8')
        cnt++;
    } else {
      break;
    }
  cout << cnt;
  return 0;
}