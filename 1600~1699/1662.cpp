// 1662: 압축
//
// - 문제
// 압축되지 않은 문자열 S가 주어졌을 때, 이 문자열중 어떤 부분 문자열은 K(Q)와 같이 압축 할 수 있다. K는 한자리 정수이고, Q는 0자리 이상의 문자열이다.
// 이 Q라는 문자열이 K번 반복된다는 뜻이다. 압축된 문자열이 주어졌을 때, 이 문자열을 다시 압축을 푸는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 압축된 문자열 S가 들어온다. S의 길이는 최대 50이다. 문자열은 (, ), 0-9사이의 숫자로만 들어온다.
//
// - 출력
// 첫째 줄에 압축되지 않은 문자열의 길이를 출력한다. 이 값은 2,147,473,647 보다 작거나 같다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  vector<pair<char, int>> v;
  int ans = 0;
  for (char c : s) {
    if (c == ')') {
      int size = 0;
      while (v.back().first != '(') {
        size += v.back().second;
        v.pop_back();
      }
      v.pop_back();
      int cnt = v.back().first - '0';
      v.back().second = cnt * size;
    } else {
      v.push_back(make_pair(c, 1));
    }
  }
  while (!v.empty()) {
    ans += v.back().second;
    v.pop_back();
  }
  cout << ans;
  return 0;
}