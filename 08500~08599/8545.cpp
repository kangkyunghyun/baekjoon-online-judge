// 8545: Zadanie próbne
//
// - 문제
// Napisz program, który odwraca podane słowo trzyliterowe.
//
// - 입력
// W pierwszym i jedynym wierszu podane jest jedno słowo trzyliterowe.
//
// - 출력
// Pierwszy i jedyny wiersz wyjścia powinien zawierać odwrócone słowo wejściowe.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  cout << s;
  return 0;
}