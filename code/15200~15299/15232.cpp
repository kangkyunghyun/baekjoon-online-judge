// 15232: Rectangles
//
// - 문제
// Read two integer numbers R and C from the standard input and then print R lines with C asterisks (*) each.
// Example (R=3, C=5):
// *****
// *****
// *****
// Example (R=2, C=10):
// **********
// **********
//
// - 입력
// The first line will contain an interger R. The number of lines to print.
// The second line will contain an integer C. The number of asterisks to print in each line.
// R, C will be at most 20.
//
// - 출력
// Print a rectangle of R lines and C columns.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int r, c;
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      cout << '*';
    cout << '\n';
  }
  return 0;
}