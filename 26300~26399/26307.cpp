// 26307: Correct
//
// - 문제
// Your best friend, Charlie, participated Taiwan Online Programming Contest (TOPC), which is a preliminary contest of the International Collegiate Programming Contest (ICPC).
// According to the rules, teams are ranked according to the most problems solved. Teams who solve the same number of problems are ranked by the least total time. The total time is the sum of the time consumed for each solved problem. The time consumed for a solved problem is the time elapsed from the beginning of the contest to the submission of the correct answer plus 20 penalty minutes for every rejected code for that problem. There is no time consumed for a problem that is not solved.
// Charlie’s team only solved one problem, and the correct answer was submitted at HH:MM AM. Fortunately, they did not submit any rejected code to the judge system. Please write a program to compute the time consumed for the problem solved by Charlie’s team. You may assume that TOPC started at 9:00 AM.
//
// - 입력
// The input contains two space-separated integers HH and MM.
//
// - 출력
// Output the time consumed for the only problem solved by Charlie’s team.
//
// - 제한
// 9 ≤ HH ≤ 11.
// 0 ≤ MM ≤ 59.

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int h, m;
  cin >> h >> m;
  cout << (h - 9) * 60 + m;
  return 0;
}