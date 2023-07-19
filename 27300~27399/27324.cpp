// 27324: ゾロ目 (Same Numbers)
//
// - 문제
// 十進法で 2 桁の整数 N が与えられる．
// N の十の位の数字と一の位の数字が同じである場合は 1 を，そうでない場合は 0 を出力せよ．
//
// - 입력
// 入力は以下の形式で標準入力から与えられる．
// N
//
// - 출력
// N の十の位の数字と一の位の数字が同じである場合は 1 を，そうでない場合は 0 を出力せよ．
//
// - 제한
// 10 ≦ N ≦ 99．
// N は整数である．

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  cout << (s[0] == s[1]);
  return 0;
}