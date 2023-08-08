// 4589: Gnome Sequencing
//
// - 문제
// In the book All Creatures of Mythology, gnomes are kind, bearded creatures, while goblins tend to be bossy and simple-minded. The goblins like to harass the gnomes by making them line up in groups of three, ordered by the length of their beards. The gnomes, being of different physical heights, vary their arrangements to confuse the goblins. Therefore, the goblins must actually measure the beards in centimeters to see if everyone is lined up in order.
// Your task is to write a program to assist the goblins in determining whether or not the gnomes are lined up properly, either from shortest to longest beard or from longest to shortest.
//
// - 입력
// The input starts with line containing a single integer N, 0 < N < 30, which is the number of groups to process. Following this are N lines, each containing three distinct positive integers less than 100.
//
// - 출력
// There is a title line, then one line per set of beard lengths. See the sample output for capitalization and punctuation.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cout << "Gnomes:\n";
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((a <= b && b <= c) || (a >= b && b >= c) ? "Ordered\n" : "Unordered\n");
  }
  return 0;
}