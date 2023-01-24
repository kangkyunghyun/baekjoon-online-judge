// 2993: 세 부분
//
// - 문제
// 독서를 싫어하는 원섭이는 책에서 단어 하나를 임의로 선택한다. 그 다음, 단어를 세 부분으로 나눈다.
// 세 부분으로 나눈 단어를 각각 순서를 뒤집는다. (첫 번째 글자와 마지막 글자의 위치를 바꾸고, 두 번째 위치와 뒤에서 두 번째 글자의 위치를 바꾸고... 이런 식으로 계속)
// 마지막으로, 이 세 단어를 나누기 전과 같은 순서로 합쳐 하나로 만든다.
// 원섭이는 사전순으로 가장 앞서는 단어를 만들려고 한다. 원섭이가 고른 단어가 주어졌을 때, 만들 수 있는 단어 중 가장 앞서는 단어를 출력하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 원섭이가 고른 단어가 주어진다. 고른 단어는 알파벳 소문자로 이루어져 있고, 길이는 3보다 크거나 같고, 50보다 작거나 같다.
//
// - 출력
// 첫째 줄에 원섭이가 만들 수 있는 단어 중 사전순으로 가장 앞서는 단어를 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  cin >> s;
  int size = s.size();
  string ans(size, 'z');
  for (int i = 0; i < size - 2; i++) {
    for (int j = i + 1; j < size - 1; j++) {
      string tmp = s;
      reverse(tmp.begin(), tmp.begin() + i + 1);
      reverse(tmp.begin() + i + 1, tmp.begin() + j + 1);
      reverse(tmp.begin() + j + 1, tmp.end());
      ans = min(ans, tmp);
    }
  }
  cout << ans;
  return 0;
}