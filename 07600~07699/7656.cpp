// 7656: 만능 오라클
//
// - 문제
// 컴퓨터 과학에서 오라클은 어떤 질문에든 대답할 수 있는 대단한 것이다. 이 문제에서 당신은 모든 것에 답변할 수 있는 오라클을 프로그램으로 작성해야 한다. 이것은, 삶, 우주, 그리고 모든 것에 대한 답변이 42라는 것을 알고 있다면, 아주 쉬운 일이다.
//
// - 입력
// 입력은 한 줄로 된 1000자 이내의 단락이 주어진다. 포함된 문자는 대소문자, 띄어쓰기, 하이픈(hyphen), 어퍼스트로피(apostrophe), 반점(comma), 세미콜론(semicolon), 온점(period)과 물음표(question mark)이다. 문장의 처음은 대문자로 시작하며, 이외에는 어디에도 대문자가 나타나지 않는다. 문장은 마침표 또는 물음표로 끝난다. 모든 질문은 "What is"로 시작한다.
//
// - 출력
// 각각의 질문에 대해, "What"은 "Forty-two"로, 끝의 "?"는 "."으로 대치하여 답변을 내어라.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  string s;
  getline(cin, s);
  int idx = 0;
  while (s.find("What is", idx) != string::npos) {
    int w = s.find("What is", idx);
    int c = 1000;
    if (s.find('.', w) != string::npos) {
      int a = s.find('.', w);
      c = min(c, a);
    }
    if (s.find('?', w) != string::npos) {
      int a = s.find('?', w);
      c = min(c, a);
    }
    if (s[c] == '?') {
      string ans = "Forty-two is";
      string tmp = s.substr(w + 7, c - w - 7);
      cout << ans << tmp << ".\n";
    }
    idx = c + 1;
  }
  return 0;
}