// 7595: Triangles
//
// - 문제
// It is not hard to draw a triangle of stars of any given size. For example, a size 5 triangle would look like this (5 stars high and 5 stars wide):
// *
// **
// ***
// ****
// *****
// Your task is to draw triangles in a number of sizes.
//
// - 입력
// Each line of input contains a single positive integer, n, 1 <= n <= 100. The last line of input contains 0. For each non-zero number, draw a triangle of that size.
//
// - 출력
// Output consists of triangles of the appropriate sizes. Each triangle is wider at the bottom. There are no gaps between the triangles.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  while (cin >> n) {
    if (!n)
      break;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++)
        cout << '*';
      cout << '\n';
    }
  }
  return 0;
}