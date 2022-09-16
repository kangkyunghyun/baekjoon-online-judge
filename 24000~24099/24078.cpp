// 24078: 余り (Remainder)
//
// - 문제
// 正の整数 X が与えられる．X を 21 で割った余りを出力せよ．
//
// - 입력
// 入力は以下の形式で標準入力から与えられる． X
//
// - 출력
// X を 21 で割った余りを出力せよ．
//
// - 제한
// 1 ≦ X ≦ 100．
// X は整数である．

#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  cout << x % 21 << '\n';
  return 0;
}