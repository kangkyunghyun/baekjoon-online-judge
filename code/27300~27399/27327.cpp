// 27327: 時間 (Hour)
//
// - 문제
// 1 日は 24 時間である．
// 整数 X が与えられる． X 日は何時間か求めよ．
//
// - 입력
// 入力は以下の形式で標準入力から与えられる．
// X
//
// - 출력
// X 日は何時間か，単位 (時間) を省いて出力せよ．
//
// - 제한
// 1 ≦ X ≦ 365．
// X は整数である．

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << n * 24;
  return 0;
}