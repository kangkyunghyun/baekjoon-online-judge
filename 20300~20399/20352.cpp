// 20352: Circus
//
// - 문제
// In the modern world, the spotlight has shifted entirely from live shows to televised recordings.  Well, not entirely... One small troupe of indomitable entertainers still holds out and puts on regular circus performances.
// The shows are extremely popular. Streaming media services nearby have caught on and, of course tried to cash in by opening their own circuses. However, they still need good acts to pull in crowds---and the natural solution has been to sneak into the big top to poach ideas and talent.
// This can not go on. The ringmaster, inspired by his distant cousins from a small village in Armorica, proposes to build a circular wall around the big top to prevent unauthorised entry.
// Figure C.1: Diagram of the indomitable circus, fencing, and the surrounding encampments of Flixium, Fundibulum, Maximillian, and Hulum. This image was adapted from an illustration of the Goseck circle by Kenny Arne Lang Antonsen.
// To build this wall, enough fencing will be needed to cover a length equal to the perimeter of the circular tent. How many metres will you need to obtain?
//
// - 입력
// The input consists of:
// One line with an integer a (1 ≤ a ≤ 10^18), the area of the circus tent in square metres.
//
// - 출력
// Output the total length of fence needed for the circus palisade wall, in metres. Your answer should have an absolute or relative error of at most 10^-6.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  double a;
  cin >> a;
  double r = sqrt(a / 3.141592);
  cout.precision(6);
  cout << fixed << 2 * 3.141592 * r;
  return 0;
}