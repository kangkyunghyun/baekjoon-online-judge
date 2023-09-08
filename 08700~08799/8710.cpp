// 8710: Koszykarz
//
// - 문제
// Kozik pragnie zostać koszykarzem. Po rozmowie z trenerem okazało się, że jest za niski. Kozik jest jednak tak zdeterminowany, że chce spełnić wymagania trenera, nawet jeśli okazałoby się to oszustwem. Wpadł więc na genialny pomysł robienia sobie guzów na głowie, aż osiągnie wymagany wzrost. Zauważył, że przy każdym uderzeniu guz się powiększa o m cm. Kozik zastanawia się ile minimalnie razy będzie musiał się uderzyć.
//
// - 입력
// W pierwszej linii wejścia 3 liczby całkowite: k, w, m (1 ≤ k ≤ 200, 1 ≤ w, m ≤ 10^9), oznaczające odpowiednio wysokość Kozika, wymaganą przez trenera wysokość oraz wartość powiększania się guza po każdym uderzeniu.
//
// - 출력
// Pierwszy i jedyny wiersz wyjścia powinien zawierać jedną liczbę całkowitą równą minimalnej liczbie uderzeń, które musi wykonać Kozik.

#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((b - a) % c ? (b - a) / c + 1 : (b - a) / c);
}