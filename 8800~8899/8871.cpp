// 8871: Zadanie próbne 2
//
// - 문제
// Wyobraźmy sobie przez chwilę, że w tym roku konkurs SKI'10 składa się z n punktowanych rund i jednej rundy próbnej. Ile zgodnie z regulaminem może się pojawić zadań w czasie całych zawodów?
//
// - 입력
// W pierwszej i jedynej linii znajduje się liczba naturalna n (1<=n<=1000).
//
// - 출력
// Twój program powinien wypisać dwie liczby oddzielone pojedynczym odstępem. Pierwsza liczba to minimalna liczba zadań jaka może pojawić się podczas n rund punktowanych i jednej rundy próbnej w trakcie SKI'10. Druga liczba to maksymalna liczba zadań w tym konkursie.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << (n + 1) * 2 << ' ' << (n + 1) * 3;
  return 0;
}