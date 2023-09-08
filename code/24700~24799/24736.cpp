// 24736: Football Scoring
//
// - 문제
// There are five ways to score points in american professional football:
//
// Touchdown - 6 points
// Field Goal - 3 points
// Safety - 2 points
// After touchdown
// 1 point (Field Goal or Safety) - Typically called the “Point after”
// 2 points (touchdown) - Typically called the “Two-point conversion”
// (https://operations.nfl.com/the-rules/nfl-video-rulebook/scoring-plays/)

// Given the box score values for two competing teams, calculate the point total for each team.
//
// - 입력
// There are two lines of input each containing five space-separated non-negative integers, T, F, S, P and C representing the number of Touchdowns, Field goals, Safeties, Points-after-touchdown and two-point Conversions after touchdown respectively. (0 ≤ T ≤ 10), (0 ≤ F ≤ 10), (0 ≤ S ≤ 10), (0 ≤ (P+C) ≤ T).
// The first line represents the box score for the visiting team, and the second line represents the box score for the home team.
//
// - 출력
// The single output line consists of two space-separated integers showing the visiting score and the home score respectively.

#include <iostream>
using namespace std;

int main() {
  int T, F, S, P, C;
  cin >> T >> F >> S >> P >> C;
  cout << T * 6 + F * 3 + S * 2 + P + C * 2 << ' ';
  cin >> T >> F >> S >> P >> C;
  cout << T * 6 + F * 3 + S * 2 + P + C * 2 << '\n';
  return 0;
}