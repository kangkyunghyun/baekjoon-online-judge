// 4354: 문자열 제곱
//
// - 문제
// 알파벳 소문자로 이루어진 두 문자열 a와 b가 주어졌을 때, a*b는 두 문자열을 이어붙이는 것을 뜻한다. 예를 들어, a="abc", b="def"일 때, a*b="abcdef"이다.
// 이러한 이어 붙이는 것을 곱셈으로 생각한다면, 음이 아닌 정수의 제곱도 정의할 수 있다.
// a^0 = "" (빈 문자열)
// a^(n+1) = a*(a^n)
// 문자열 s가 주어졌을 때, 어떤 문자열 a에 대해서 s=a^n을 만족하는 가장 큰 n을 찾는 프로그램을 작성하시오.
//
// - 입력
// 입력은 10개 이하의 테스트 케이스로 이루어져 있다. 각각의 테스트 케이스는 s를 포함한 한 줄로 이루어져 있다. s의 길이는 적어도 1이며, 백만글자를 넘지 않는다. 마지막 테스트 케이스의 다음 줄은 마침표이다.
//
// - 출력
// 각각의 테스트 케이스에 대해, s=a^n을 만족하는 가장 큰 n을 찾은 뒤 출력한다.

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int fail(string pattern) {
  int M = pattern.size();
  vector<int> fail(M, 0);
  for (int i = 1, j = 0; i < M; i++) {
    while (j > 0 && pattern[i] != pattern[j])
      j = fail[j - 1];
    if (pattern[i] == pattern[j])
      fail[i] = ++j;
  }
  if (M % (M - fail[M - 1]) == 0)
    return M / (M - fail[M - 1]);
  else
    return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  while (cin >> s) {
    if (s == ".")
      break;
    cout << fail(s) << '\n';
  }
  return 0;
}