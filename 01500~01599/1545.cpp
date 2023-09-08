// 1545: 안티 팰린드롬
//
// - 문제
// 만약 어떤 문자열 P가 있을 때, P[i]와 P[n-i-1] (0 ≤ i<(n-1)/2, n = P의 길이)이 모두 다를 때, P는 안티 팰린드롬 문자열이라고 한다. 이 말은 P와 P를 대칭한 문자열 P'가 있을 때,모든 문자가 달라야 안티 팰린드롬 문자열이란 소리다. (단, 문자열의 길이가 홀수인 경우에는, 가운데 문자는 같아도 된다) 예를 들어, "c", "cpp", "java"는 안티 팰린드롬 문자열이고, “test", "pp", ”weather"는 안티 팰린드롬 문자열이 아니다.
// 문자열 S가 주어졌을 때, 이 문자열을 재배치 시켜서 안티 팰린드롬 문자열을 만드는 프로그램을 작성하시오. 만약 가능한 경우가 여러 가지 있다면, 사전순으로 가장 앞서는 것을 출력하시오.
//
// - 입력
// 첫째 줄에 문자열 S가 주어진다. 이 길이는 최대 50이고, 알파벳 소문자로만 이루어져 있다.
//
// - 출력
// 첫째 줄에 정답을 출력한다. 만약 불가능한 경우에는 -1을 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int size = s.size();
  sort(s.begin(), s.end());
  int left, right;
  if (size % 2 == 0) {
    left = size / 2 - 1;
    right = size / 2;
  } else {
    left = size / 2 - 1;
    right = size / 2 + 1;
  }
  while (left >= 0) {
    if (s[left] == s[right]) {
      int idx = right;
      while (s[idx] == s[right]) {
        idx++;
        if (idx == size) {
          cout << "-1\n";
          return 0;
        }
      }
      char tmp = s[right];
      s[right] = s[idx];
      s[idx] = tmp;
    }
    left--;
    right++;
  }
  cout << s << '\n';
  return 0;
}