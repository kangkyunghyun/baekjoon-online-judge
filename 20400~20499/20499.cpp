// 20499: Darius님 한타 안 함?
//
// - 문제
// 아무래도 우리 팀 다리우스가 고수인 것 같다. 그의 K/D/A를 보고 그가 「진짜」인지 판별해 보자.
//  K+A < D이거나, D = 0이면 그는 「가짜」이고, 그렇지 않으면 「진짜」이다.
//
// - 입력
//  K/D/A가 주어진다.
//
// - 출력
// 그가 「진짜」이면 gosu, 「가짜」이면 hasu를 출력한다.
//
// - 제한
//  0 ≤ K, D, A ≤ 20

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int k, d, a;
  char temp;
  cin >> k >> temp >> d >> temp >> a;
  if (k + a < d || d == 0)
    cout << "hasu";
  else
    cout << "gosu";
  return 0;
}