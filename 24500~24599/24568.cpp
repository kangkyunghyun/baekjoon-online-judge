// 24568: Cupcake Party
//
// - 문제
// A regular box of cupcakes holds 8 cupcakes, while a small box holds 3 cupcakes.
// There are 28 students in a class and a total of at least 28 cupcakes.
// Your job is to determine how many cupcakes will be left over if each student gets one cupcake.
//
// - 입력
// The input consists of two lines.
//
// The first line contains an integer R ≥ 0, representing the number of regular boxes.
// The second line contains an integer S ≥ 0, representing the number of small boxes.
//
// - 출력
// Output the number of cupcakes that are left over.

#include <iostream>
using namespace std;

int main() {
  int r, s;
  cin >> r >> s;
  cout << r * 8 + s * 3 - 28 << '\n';
  return 0;
}