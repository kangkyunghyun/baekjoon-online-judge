// 27331: 2 桁の整数 (Two-digit Integer)
//
// - 문제
// 2 つの数字 A, B が与えられる．
// 十の位が A であり，一の位が B である 2 桁の正の整数を出力せよ．
//
// - 입력
// 入力は以下の形式で与えられる．
// A
// B
//
// - 출력
// 十の位が A であり，一の位が B である 2 桁の正の整数を出力せよ．
//
// - 제한
// A は 1，2，3，4，5，6，7，8，9 のいずれかである．
// B は 0，1，2，3，4，5，6，7，8，9 のいずれかである．

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << a << b;
  return 0;
}