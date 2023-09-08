// 18414: X に最も近い値 (The Nearest Value)
//
// - 문제
// 整数 X, L, R が与えられる. L 以上 R 以下の整数のうち，X との差の絶対値が最も小さいものを出力せよ．そのような整数はちょうど 1 つだけ存在することが証明できる．
//
// - 입력
// 入力は以下の形式で標準入力から与えられる．
// X L R
//
// - 출력
// L 以上 R 以下の整数のうち，X との差の絶対値が最も小さいものを出力せよ．
//
// - 제한
// 1 ≦ X ≦ 100 000．
// 1 ≦ L ≦ R ≦ 100 000．

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x, l, r;
  cin >> x >> l >> r;
  if (x <= l)
    cout << l;
  else if (x >= r)
    cout << r;
  else
    cout << x;
  return 0;
}