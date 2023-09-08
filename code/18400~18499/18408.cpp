// 18408: 3 つの整数 (Three Integers)
//
// - 문제
// 3 つの整数 A, B, C が与えられる．A, B, C はそれぞれ 1 または 2 である．1 と 2 のうち，どちらが多くあるか．
//
// - 입력
// 入力は以下の形式で標準入力から与えられる．
// A B C
//
// - 출력
// 1 と 2 のうち，個数が多い方を出力せよ．
//
// - 제한
// A, B, C はそれぞれ 1 または 2 である．

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a[3] = {0}, b;
  for (int i = 0; i < 3; i++) {
    cin >> b;
    a[b]++;
  }
  cout << (a[1] > a[2] ? 1 : 2);
  return 0;
}