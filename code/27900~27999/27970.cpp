// 27970: OX
//
// - 문제
// O와 X로 이루어진 문자열이 주어진다. 모든 문자를 X로 만들 때까지 다음 연산을 반복할 때, 시행하는 연산의 횟수를 구하시오.
// 문자열의 가장 왼쪽에 있는 O를 X로 바꾸고, 그보다 왼쪽에 있는 X를 전부 O로 바꾼다.
//
// - 입력
// 첫째 줄에 O와 X로 이루어진 문자열이 주어진다. 문자열의 길이는 1 이상 100,000 이하이다.
//
// - 출력
// 첫째 줄에 연산의 횟수를 10^9 + 7로 나눈 나머지를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long ans = 0, mul = 1, mod = 1e9 + 7;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'O')
      ans += mul;
    ans %= mod;
    mul *= 2;
    mul %= mod;
  }
  cout << ans;
  return 0;
}