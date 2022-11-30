// 24883: 자동완성
//
// - 문제
// 숭고한 알고리즘 대회를 운영하게 된 성서는 참가자들에게 상금을 주기 위해 여러 기업에 후원 요청을 보냈고, D2 CAMPUS를 통해 대회 상금을 지원받게 되었다.
// 상금을 사비로 부담하지 않아도 돼서 감사한 성서는 검색창에 N 또는 n이 입력되면 Naver D2가 자동 완성되도록 설정하고 싶다. 알파벳 하나를 입력받아서 그 알파벳이 N 또는 n이면 Naver D2를 출력하고, 아니라면 Naver Whale을 출력하는 프로그램을 작성해보자.
//
// - 입력
// 첫 줄에 알파벳 하나가 주어진다.
//
// - 출력
// 주어진 알파벳이 N 또는 n 이면 "Naver D2", 아니라면 "Naver Whale"을 따옴표를 제외하고 출력한다.

#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  cin >> c;
  if (c == 'N' || c == 'n')
    cout << "Naver D2";
  else
    cout << "Naver Whale";
  return 0;
}