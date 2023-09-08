// 16099: Larger Sport Facility
//
// - 문제
// In a lot of places in the world, elite universities come in pairs and their students like to challenge each other every year. In England, Oxford and Cambridge are famous for The Boat Race, an annual rowing race that opposes them. In Switzerland, students from Zürich and Lausanne battle in a famous annual ski challenge.
// TelecomParisTech and Eurecom, two famous French schools, are also planning to organize a multi-sport tournament. They have already agreed on the choice of sports and the rules of the game, but the only point of disagreement is on where the contest should be hosted. Indeed, every school has been bragging for years about the wonderful sport facilities that they have.
// At last, it was agreed that the competition would be hosted at the school which has the larger rectangular sports field. The only thing left is to determine which school this is: given the size of the fields, determine which school has the field with the larger surface.
//
// - 입력
// The input consists of several test cases. The first line contains an integer indicating the number of test cases. Each test case follows. Each test case consists of a single line containing 4 integers 1 ≤ lt, wt, le, we ≤ 109 separated by single spaces: lt and wt represent the length and width of the sports field of TelecomParisTech, and le and we represent the length and width of the sports field at Eurecom.
//
// - 출력
// For each test case in the input, your program should produce one line. The contents of the line should be the name of the school that has the facility with the larger area: TelecomParisTech or Eurecom. In case of a tie, the contents of the line should be Tie. There should be no blank lines in your output.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * b > c * d)
      cout << "TelecomParisTech\n";
    else if (a * b < c * d)
      cout << "Eurecom\n";
    else
      cout << "Tie\n";
  }
  return 0;
}