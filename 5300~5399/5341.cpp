// 5341: Pyramids
//
// - 문제
// A pyramid of blocks is constructed by first building a base layer of n blocks and then adding n-1 blocks to the next layer. This process is repeated until the top layer only has one block.
// You must calculate the number of blocks needed to construct a pyramid given the size of the base. For example, a pyramid that has a base of size 4 will need a total of 10 blocks.
//
// - 입력
// The input will be a sequence of integers, one per line. The end of input will be signaled by the integer 0, and does not represent the base of a pyramid. All integers, other than the last (zero), are positive.
//
// - 출력
// For each positive integer print the total number of blocks needed to build the pyramid with the specified base.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  while (1) {
    int x, ans = 0;
    cin >> x;
    if (x == 0)
      break;
    while (x > 0) {
      ans += x;
      x--;
    }
    cout << ans << '\n';
  }
  return 0;
}