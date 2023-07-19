// 27328: 三方比較 (Three-Way Comparison)
//
// - 문제
// 2 つの整数 A, B が与えられる．
// A と B の大小を比較し，A ＜ B ならば -1 を，A ＝ B ならば 0 を，A ＞ B ならば 1 を出力せよ．
//
// - 입력
// 入力は以下の形式で標準入力から与えられる．
// A
// B
//
// - 출력
// A ＜ B ならば -1 を，A ＝ B ならば 0 を，A ＞ B ならば 1 を出力せよ．
//
// - 제한
// 1 ≦ A ≦ 1000．
// 1 ≦ B ≦ 1000．
// A, B は整数である．

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a < b)
    cout << -1;
  else if (a > b)
    cout << 1;
  else
    cout << 0;
  return 0;
}