// 1157: 단어 공부
//
// - 문제
// 알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.
//
// - 입력
// 첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.
//
// - 출력
// 첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

#include <iostream>
using namespace std;

int main() {
  int arr[26] = {0};
  int max = 0, result, cnt = 0;
  string str, alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= 97 && str[i] <= 122) {
      str[i] -= 32;
    }
  }
  for (int j = 0; j < alphabet.length(); j++) {
    for (int k = 0; k < str.length(); k++) {
      if (alphabet[j] == str[k]) {
        arr[j] += 1;
      }
    }
  }
  for (int l = 0; l < 26; l++) {
    if (arr[l] > max) {
      max = arr[l];
      result = alphabet[l];
    }
  }
  for (int m = 0; m < 26; m++) {
    if (arr[m] == max) {
      cnt++;
    }
  }
  if (cnt > 1) {
    cout << '?' << '\n';
  } else {
    cout << (char)result << '\n';
  }
  return 0;
}