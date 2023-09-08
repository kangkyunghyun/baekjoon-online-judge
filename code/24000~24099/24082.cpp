// 24082: 立方体 (Cube)
//
// - 문제
// 一辺の長さが x cm の立方体の体積は (x × x × x) cm3 である．
// 整数 X が与えられる．一辺の長さが X cm の立方体の体積は何 cm3 か求めよ．
//
// - 입력
// 入力は以下の形式で標準入力から与えられる． X
//
// - 출력
// 一辺の長さが X cm の立方体の体積が何 cm3 か，単位 (cm3) を省いて出力せよ．
//
// - 제한
// 1 ≦ X ≦ 100．
// X は整数である．

#include <iostream>
using namespace std;

int main() {
  int x;
  cin >> x;
  cout << x * x * x << '\n';
  return 0;
}