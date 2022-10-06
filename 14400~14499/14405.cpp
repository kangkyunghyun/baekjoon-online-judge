// 14405: 피카츄
//
// - 문제
// 피카츄는 "pi", "ka", "chu"를 발음할 수 있다. 따라서, 피카츄는 이 세 음절을 합친 단어만 발음할 수 있다. 예를 들면, "pikapi"와 "pikachu"가 있다.
// 문자열 S가 주어졌을 때, 피카츄가 발음할 수 있는 문자열인지 아닌지 구하는 프로그램을 작성하시오.
//
// - 입력
// 첫째 줄에 문자열 S가 주어진다. 문자열은 알파벳 소문자로 이루어진 문자열이며, 길이는 5000을 넘지 않는다.
//
// - 출력
// 문자열 S가 "pi", "ka", "chu"를 이어 붙여서 만들 수 있으면 "YES"를 아니면 "NO"를 출력한다.

#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (str.find("pi") != string::npos) {
      int index = str.find("pi");
      str[index] = '*';
      str[index + 1] = '*';
    }
    if (str.find("ka") != string::npos) {
      int index = str.find("ka");
      str[index] = '*';
      str[index + 1] = '*';
    }
    if (str.find("chu") != string::npos) {
      int index = str.find("chu");
      str[index] = '*';
      str[index + 1] = '*';
      str[index + 2] = '*';
    }
  }
  int cnt = 0;
  for (int i = 0; i < str.length(); i++)
    if (str[i] == '*')
      cnt++;
  if (cnt == str.length())
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
  return 0;
}